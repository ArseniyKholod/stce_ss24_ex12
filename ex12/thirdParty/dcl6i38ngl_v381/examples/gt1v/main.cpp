/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

// This example demostrates basic use of tangent vector mode. It
// computes the mxn Jacobian by seeding the input tangents to the
// identity matrix in R^n.
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
  // Using first-order tangent vector mode.
  constexpr std::size_t n = 4, m = 2;
  using mode_t = dco::gt1v<double, n>;
  using type = mode_t::type;

  // Inputs.
  std::vector<type> x(n, 1.0);

  // Seed identity matrix to the input tangents.
  for (std::size_t i = 0; i < n; ++i) {
    dco::derivative(x[i])[i] = 1.0;
  }

  // Evaluate function only once. Implicitly performs Jacobian matrix
  // product, the matrix being the identity in R^n.
  auto y = f(x);

  // Print output values.
  std::cout << "y = [ ";
  for (auto const& yi : y) {
    std::cout << yi << " ";
  }
  std::cout << "]" << std::endl;

  // Print Jacobian.
  for (std::size_t i = 0; i < n; ++i) {
    std::cout << "dy / dx[" << i << "] = [ ";
    for (std::size_t j = 0; j < m; ++j) {
      std::cout << dco::derivative(y[j])[i] << " ";
    }
    std::cout << "]" << std::endl;
  }
}
