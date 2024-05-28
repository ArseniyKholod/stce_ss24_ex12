/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

// This example demostrates how to handle the tape, if it gets reused
// for different functions. It computes the gradients of two scalar
// multi-variate functions f and g. Please see basic first order
// adjoint example first (ga1s).
#include "dco.hpp"

// Implementation of y = f(x), which we differentiate in main.
template <typename T> T f(const std::vector<T>& x) {
  T y = 0;
  for (auto const& xi : x)
    y += sin(xi);
  return y;
}
template <typename T> T g(const std::vector<T>& x) {
  T y = 1;
  for (auto const& xi : x)
    y *= cos(xi);
  return y;
}

int main() {
  // Using first-order adjoint mode.
  constexpr std::size_t n = 4;
  using mode_t = dco::ga1s<double>;
  using type = mode_t::type;

  // Inputs.
  std::vector<type> x(n);
  for (std::size_t i = 0; i < n; ++i)
    x[i] = sin(static_cast<double>(i + 1));

  dco::smart_tape_ptr_t<mode_t> tape;
  tape->register_variable(x);

  // Record tape for f.
  auto y = f(x);

  tape->register_output_variable(y);

  // Print output.
  std::cout << "f(x) = " << y << std::endl;

  dco::derivative(y) = 1.0;
  tape->interpret_adjoint();

  // Print gradient of f.
  std::cout << "df = [";
  for (auto const& xi : x) {
    std::cout << dco::derivative(xi) << " ";
  }
  std::cout << "]" << std::endl;

  // Reset tape. This frees the memory that was required for the
  // recording of f. Otherwise, the tape would just grow.
  tape->reset();

  // All inputs need to be re-registered.
  tape->register_variable(x);

  // Record tape for g.
  y = g(x);

  tape->register_output_variable(y);

  // Print output.
  std::cout << "g(x) = " << y << std::endl;

  dco::derivative(y) = 1.0;
  tape->interpret_adjoint();

  // Print gradient of g.
  std::cout << "dg = [";
  for (auto const& xi : x) {
    std::cout << dco::derivative(xi) << " ";
  }
  std::cout << "]" << std::endl;
}
