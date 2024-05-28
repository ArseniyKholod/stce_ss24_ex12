/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

// This example demostrates basic use of 2nd order adjoint mode. It computes the
// nxn Hessian by letting the input tangents iterate over the
// Cartesian basis vectors in R^n.
#include "dco.hpp"

// Implementation of y = f(x), which we differentiate in main.
// n = 4, m = 1.
// NOTE: We've change the function to only have a single output.
template <typename T> T f(const std::vector<T>& x) {
  std::vector<T> y(2);
  T v = tan(x[2] * x[3]);
  T w = x[1] - v;
  y[0] = x[0] * v / w;
  y[1] = y[0] * x[1];
  return y[0] + y[1];
}

int main() {
  // Using second-order adjoint mode.
  constexpr std::size_t n = 4;
  using mode_t = dco::ga1s<dco::gt1s<double>::type>;
  using type = mode_t::type;

  // Inputs.
  std::vector<type> x(n, 1.0);

  dco::smart_tape_ptr_t<mode_t> tape;

  // Iterate over the Cartesian basis vectors in R^m.
  for (std::size_t j = 0; j < n; ++j) {
    tape->register_variable(x);

    // Seed j-th Cartesian basis vector to the output adjoints.
    dco::derivative(dco::value(x[j])) = 1.0;

    // Record tape for f. This is only required once!
    auto y = f(x);

    // Print output value.
    if (j == 0) {
      std::cout << "y = " << y << std::endl;
    }

    tape->register_output_variable(y);
    dco::derivative(y) = 1.0;

    // Interpret the tape for j-th output.
    tape->interpret_adjoint();

    // Print Hessian line by line.
    std::cout << "ddy[" << j << "] = [ ";
    for (std::size_t i = 0; i < n; ++i) {
      std::cout << dco::derivative(dco::derivative(x[i])) << " ";
    }
    std::cout << "]" << std::endl;

    // Reset all adjoints to zero.
    tape->reset();
    dco::derivative(dco::value(x[j])) = 0.0;
  }
}
