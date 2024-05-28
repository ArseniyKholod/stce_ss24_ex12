/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

//** This examples demonstrates how to use threadlocal tapes to
//** compute pathwise adjoints in parallel with OpenMP. The
//** calibration is only recorded on the main tape. The threadlocal
//** tape do not copy the main tape.
#include "dco.hpp"

//** Using C++ random number generator.
#include <random>
//** OpenMP.
#include <omp.h>

//** Templated pricer; implements mock ups of calibration and pricing
//** by Monte Carlo.
template <typename T> struct pricer {

  //** Number of paths in the Monte Carlo.
  const std::size_t n_paths = 10000;
  //** Number of timesteps in mocked up path implementation.
  const std::size_t n_timesteps = 500;

  std::vector<double> random_numbers;

  pricer() : random_numbers(n_paths * n_timesteps) {
    //** Generate random numbers.
    std::mt19937 mt(1);
    std::uniform_real_distribution<double> dist(1.0, 10.0);
    for (auto& r : random_numbers) {
      r = dist(mt);
    }
  }

  //** Mocked up calibration routine.
  std::vector<T> calibration(std::vector<T> const& data) {
    std::vector<T> ret(data.size());
    for (std::size_t i = 0; i < data.size(); ++i) {
      ret[i] = cos(data[i]);
    }
    return ret;
  }

  //** Mocked up Monte Carlo simulation using parameters.
  T monte_carlo(std::vector<T> const& parameters) {
    T p = 0;
    //** We need to store a pointer to the global tape of the main
    //** thread, so that we can increment adjoints in there from the
    //** other threads.
    auto thread0_tape = dco::mode<T>::global_tape;

    //** Thread parallel Monte Carlo.
#pragma omp parallel
    {
      //** We have to synchronize the thread local tapes on the fresh
      //** threads with the main tape. This only adjusts iterators
      //** within the tape, no copy is performed. The fresh thread
      //** tapes are still empty after synchronization.
      if (omp_get_thread_num() != 0) {
        dco::mode<T>::global_tape->synchronize_with(thread0_tape);
      }
#pragma omp barrier

      //** Here we do pathwise adjoints with early propagation,
      //** since we know the output adjoint already (it's 1 /
      //** n_paths). So we save the current position for
      //** interpretation and resetting afterwards.
      auto pos = dco::mode<T>::global_tape->get_position();

      //** Run parallel loop.
#pragma omp for
      for (int pth = 0; pth < static_cast<int>(n_paths); ++pth) {
        //** Record single path.
        T pl = path(parameters, pth);

        //** Resolve race condition on p and avoid messing up tape
        //** index of p by overwriting it from different tapes. We
        //** just treat it as passive here for simplicity.
#pragma omp critical
        p += dco::value(pl);
        //** Seeding. We know the output adjoint already.
        dco::derivative(pl) = 1.0 / n_paths;
        //** Compute adjoints of path and accumulate per thread.
        dco::mode<T>::global_tape->interpret_adjoint_and_reset_to(pos);
      }

      //** Reduce adjoints from various thread local tapes.
      //**  We have two options here:
      if (omp_get_thread_num() != 0) {
        //**   - use the parameters explicitly; this is presumably more efficient.
        if (false) {
          for (auto const& par : parameters) {
#pragma omp atomic
            thread0_tape->adjoint(par) += dco::derivative(par);
          }
        }
        //**   - reduce full vector up to posision.
        for (dco::index_t i = 1; i <= pos.index(); ++i) {
#pragma omp atomic
          thread0_tape->adjoints()[i] += dco::mode<T>::global_tape->adjoints()[i];
        }
      }
    }
    return p / n_paths;
  }

  //** Mocked up path calculation using parameters.
  T path(std::vector<T> const& parameters, int pth) {
    T p = 0;
    for (std::size_t time = 0; time < n_timesteps; ++time) {
      p += sin(random_numbers[pth * n_timesteps + time] * parameters[time % parameters.size()]);
    }
    return p;
  }

  T price(std::vector<T> data) {

    //** Calibrate to market data.
    //*** This is done on the main thread only.
    std::vector<T> parameters = calibration(data);

    //** Run monte carlo pricer.
    return monte_carlo(parameters);
  }
};

//** Compute gradient of price w.r.t. data using dco::ga1s.
std::vector<double> dprice(std::vector<double> const& data) {
  using mode_t = dco::ga1s<double>;
  using type = mode_t::type;

  //** Create all thread tapes. Each thread has global tape.
#pragma omp parallel
  mode_t::global_tape = mode_t::tape_t::create();

  //** Default dco/c++ driver for early propagation in pathwise
  //** adjoints.
  std::vector<type> adata(begin(data), end(data));
  mode_t::global_tape->register_variable(adata);

  pricer<type> P;
  P.price(adata);

  mode_t::global_tape->interpret_adjoint();
  std::vector<double> grad = dco::derivative(adata);

#pragma omp parallel
  mode_t::tape_t::remove(mode_t::global_tape);

  return grad;
}

int main() {
  //** Our parameters.
  std::vector<double> data{1.0, 1.1, 1.2};
  //** Compute and print gradient.
  std::vector<double> grad = dprice(data);

  //** Since C++ random number generator is not portable, we can not
  //** print the values to std::cout, since those would be checked on
  //** correctness by our build system. We use std::cerr instead.
  for (auto const& g : grad) {
    std::cerr << std::setprecision(10) << g << std::endl;
  }
}
