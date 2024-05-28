/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include <vector>

#include "dco.hpp"
// This example program demonstrates how a custom hook can be inserted into interpreter
// to monitor edge propagation.

// Operator of the discretised 1D Poisson equation:
template <typename T> void f(std::vector<T>& x, std::vector<T>& y) {
  for (std::size_t i = 0; i < x.size(); i++) {
    if (i == 0) {
      y[i] = 2 * x[i] - x[i + 1];
    } else if (0 < i && i < x.size() - 1) {
      y[i] = -x[i - 1] + 2 * x[i] - x[i + 1];
    } else {
      y[i] = -x[i - 1] + 2 * x[i];
    }
  }
}

int main() {

  using mode_t = dco::ga1s<double>;
  using type = mode_t::type;

  dco::smart_tape_ptr_t<mode_t> tape;

  size_t n = 4;
  std::vector<type> x(n, 1.0), y(n, 0.0);
  tape->register_variable(x);
  f(x, y);
  tape->register_output_variable(y);

  // Indices of inputs with nonzero adjoints:
  std::vector<dco::index_t> indices;
  // Store Jacobian matrix in coordinate sparse format:
  std::vector<dco::index_t> rows, cols, vals;
  // A reference to the internal vector of adjoints:
  auto& adjoints = tape->adjoints();

  for (size_t j = 0; j < n; j++) {
    // Extract the row, column and value components of the Jacobian matrix stored in COO Sparse format
    // and indices of inputs with nonzero adjoints.
    auto lambda = [&](dco::index_t idx, mode_t::derivative_t const& inc) {
      if (idx <= dco::tape_index(x.back()) && inc != 0.0) {
        // Fill COO matrix:
        rows.push_back(j);
        cols.push_back(idx - 1);
        vals.push_back(adjoints[idx]);
        // Get indices of inputs with nonzero adjoints:
        indices.push_back(idx);
      }
    };
    tape->zero_adjoints();
    dco::derivative(y[j]) = 1.0;
    tape->interpret_adjoint(lambda);

    std::cout << "Printing indices of nonzero adjoints for j=" << j << ":" << std::endl;
    for (size_t i = 0; i < indices.size(); i++) {
      std::cout << "Input variable stored in index " << indices[i];
      std::cout << " has corresponding derivative = " << adjoints[indices[i]] << "." << std::endl;
    }
    indices.clear();
    std::cout << std::endl << std::endl;
  }

  // Multiple occurences of the same (row,column) pair could appear in this matrix structure.
  // In such case, the value of the element stored in the (row,column) position is the sum of
  // the value components in the occurences.
  std::cout << "Printing elements of the sparse Jacobian matrix stored in coordinate sparse format:" << std::endl;
  for (std::size_t i = 0; i < rows.size(); i++) {
    std::cout << "(row = " << rows[i] << ", column = " << cols[i] << ", value = " << vals[i] << ")" << std::endl;
  }
}
