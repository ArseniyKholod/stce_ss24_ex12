/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

//** Demonstrator on how to use finite difference approximation for an
//** intermediate function f2 for the following configuration:
//**   f1: R^n -> R^m
//**   f2: R^m -> R^k
//**   f3: R^k -> R
//**   and y = f3(f2(f1(x)))
#include "dco.hpp"

constexpr std::size_t k = 2, n = 4, m = 3;
//** Set to false for plain taping.
constexpr bool use_finite_differences = true;

//** Arbitrary function f1.
template <typename T> std::vector<T> f1(std::vector<T> const& x) {
  std::vector<T> y(m);

  for (std::size_t i = 0; i < y.size(); ++i) {
    for (std::size_t j = 0; j < x.size(); ++j) {
      y[i] += sin(x[j]);
    }
  }

  return y;
}

//** Arbitrary function f2. This is the implementation used for taping
//** or finite differences.
template <typename T> std::vector<T> f2_impl(std::vector<T> const& x) {
  std::vector<T> y(k);
  for (std::size_t i = 0; i < y.size(); ++i) {
    y[i] = sin(x[i % x.size()] * x[(i + 1) % x.size()]);
  }
  return y;
}

template <typename T> std::vector<T> f2(std::vector<T> const& x) {

  if (use_finite_differences) {
    //** Use FD Jacobian of f2_impl(...) in callback to propagate adjoints.
    //** We run f2 without taping. Could be done with passive (double)
    //** values as well. Here we switch the tape off and use active
    //** data.
    dco::tape(x)->switch_to_passive();
    auto y = f2_impl(x);
    dco::tape(x)->switch_to_active();
    //** Output needs to be registered to trigger subsequent tape
    //** recording of f3.
    dco::tape(x)->register_variable(y);

    //** The callback, which gets called during tape
    //** interpretation. It uses finite differences to propagate
    //** output adjoint to input adjoints. We capture automatically x
    //** and y by copy here.
    auto callback = [=]() {
      //** We can perform the finite difference computation with doubles,
      //** i.e., value_t.
      using value_t = typename dco::mode<T>::value_t;

      constexpr double h = 1e-12;
      //** We need copies for the finite difference algorithm.
      std::vector<value_t> xc(x.size()), yc;
      xc = dco::value(x);

      //** Compute Jacobian matrix column-by-column using finite
      //** differences:
      for (std::size_t i = 0; i < x.size(); ++i) {
        xc[i] += h;
        yc = f2_impl(xc);
        //** This computes the finite difference approximation and does
        //** the transposed multiplication of the incoming adjoints
        //** in place. No need to store the Jacobian.
        for (std::size_t j = 0; j < y.size(); ++j) {
          double jac_entry = (yc[j] - dco::value(y[j])) / h;
          dco::derivative(x[i]) += dco::derivative(y[j]) * jac_entry;
        }
        xc[i] -= h;
      }
    };

    //** The lambda is moved into the tape; this avoids potential
    //** copies of the checkpoint.
    dco::tape(x)->insert_callback(std::move(callback));
    return y;
  } else {
    //** Just record tape.
    return f2_impl(x);
  }
}

template <typename T> T f3(std::vector<T> const& x) {
  T y = 0;
  //** Sum of squares.
  for (auto const& xi : x)
    y += xi * xi;
  return y;
}

int main() {

  using mode_t = dco::ga1s<double>;
  using type = mode_t::type;

  dco::smart_tape_ptr_t<mode_t> tape;

  //** Overall inputs; allocate and initialize.
  std::vector<type> x(n);
  for (std::size_t i = 0; i < n; ++i)
    x[i] = sin(static_cast<double>(i + 1));
  tape->register_variable(x);

  //** Record tape.
  auto y = f3(f2(f1(x)));

  dco::derivative(y) = 1.0;
  tape->interpret_adjoint();

  std::cout << "Gradient:" << std::endl;
  for (auto const& xi : x)
    std::cout << dco::derivative(xi) << " ";
  std::cout << std::endl;
}
