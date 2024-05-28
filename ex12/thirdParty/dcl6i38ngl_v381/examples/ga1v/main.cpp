/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

// This example demostrates basic use of adjoint vector mode. It
// computes the mxn Jacobian by seeding the output adjoints to the
// identity matrix in R^m.
#include "dco.hpp"

// Implementation of y = f(x), which we differentiate in main.
// n = 4, m = 2.
template <typename T> std::vector<T> f(const std::vector<T>& x) {
  std::vector<T> y(2);
  T v = tan(x[2] * x[3]);
  T w = x[1] - v;
  y[0] = x[0] * v / w;
  y[1] = y[0] * x[1];
  return y;
}

int main() {
  // Using first-order adjoint vector mode.
  constexpr std::size_t n = 4, m = 2;
  using mode_t = dco::ga1v<double, m>;
  using type = mode_t::type;

  // Inputs.
  std::vector<type> x(n, 1.0);

  dco::smart_tape_ptr_t<mode_t> tape;
  tape->register_variable(x);

  // Record tape for f. This is only required once!
  auto y = f(x);

  tape->register_output_variable(y);

  // Seed identity matrix in the output adjoints.
  for (std::size_t i = 0; i < m; ++i) {
    dco::derivative(y[i])[i] = 1.0;
  }
  // Interpret the tape. Also only once! Implicitly performs the
  // transpoed Jacobian matrix product, the matrix being the identity
  // in R^m.
  tape->interpret_adjoint();

  // Print output values.
  std::cout << "y = [ ";
  for (auto const& yi : y) {
    std::cout << yi << " ";
  }
  std::cout << "]" << std::endl;

  // Print Jacobian.
  for (std::size_t j = 0; j < m; ++j) {
    std::cout << "dy[" << j << "] = [ ";
    for (std::size_t i = 0; i < n; ++i) {
      std::cout << dco::derivative(x[i])[j] << " ";
    }
    std::cout << "]" << std::endl;
  }
}
