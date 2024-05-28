/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

// This example demostrates basic use of combined tangent/adjoint
// mode. It computes the mxn Jacobian by letting the input tangents
// and output adjoints iterate over the respective Cartesian basis
// vectors in R^n and R^m.
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
  constexpr std::size_t n = 4, m = 2;
  using mode_t = dco::gtas<double>;
  using type = mode_t::type;

  // Inputs.
  std::vector<type> x(n, 1.0);

  // Using first-order adjoint mode.
  dco::smart_tape_ptr_t<mode_t> tape;
  tape->register_variable(x);

  // Record tape for f. This is only required once!
  auto y = f(x);

  tape->register_output_variable(y);

  // Print output values.
  std::cout << "y = [ ";
  for (auto const& yi : y) {
    std::cout << yi << " ";
  }
  std::cout << "]" << std::endl;

  // Iterate over the Cartesian basis vectors in R^m.
  for (std::size_t j = 0; j < m; ++j) {
    // Seed j-th Cartesian basis vector to the output adjoints.
    dco::adjoint(y[j]) = 1.0;

    // Interpret the tape for j-th output.
    tape->interpret_adjoint();

    // Print Jacobian.
    std::cout << "dy[" << j << "] = [ ";
    for (std::size_t i = 0; i < n; ++i) {
      std::cout << dco::adjoint(x[i]) << " ";
    }
    std::cout << "]" << std::endl;

    // Reset all adjoints to zero.
    tape->zero_adjoints();
  }

  // Using first-order tangent mode.
  // Iterate over the Cartesian basis vectors in R^n.
  for (std::size_t i = 0; i < n; ++i) {

    // Seed i-th Cartesian basis vector to the input tangents.
    dco::tangent(x[i]) = 1.0;

    // Propagate tangents from inputs to outputs, i.e. perform
    // implicit Jacobian vector product.
    y = f(x);

    // Reset input tangent.
    dco::tangent(x[i]) = 0.0;

    if (i == 0) {
      // Print output values (just once on first iteration).
      std::cout << "y = [ ";
      for (auto const& yi : y) {
        std::cout << yi << " ";
      }
      std::cout << "]" << std::endl;
    }

    // Print Jacobian.
    std::cout << "dy / dx[" << i << "] = [ ";
    for (std::size_t j = 0; j < m; ++j) {
      std::cout << dco::tangent(y[j]) << " ";
    }
    std::cout << "]" << std::endl;
  }
}
