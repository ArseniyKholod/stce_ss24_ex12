/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <vector>
#include "dco.hpp"

using namespace std;
using namespace dco;

const std::size_t l = 5;

typedef double DCO_BASE_TYPE;
typedef ga1vm<DCO_BASE_TYPE, l> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

#include "f.hpp"

void driver(const vector<double>& xv, vector<vector<double>>& xa, vector<double>& yv, vector<vector<double>>& ya) {
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  size_t n = xv.size(), m = yv.size();
  vector<DCO_TYPE> x(n), y(m);
  for (size_t i = 0; i < n; i++) {
    x[i] = xv[i];
    tape->register_variable(x[i]);
  }
  f(x, y);
  for (std::size_t i = 0; i < m; i++) {
    tape->register_output_variable(y[i]);
    yv[i] = value(y[i]);
    for (std::size_t j = 0; j < l; j++)
      derivative(y[i])[j] = ya[i][j];
  }
  for (size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < l; j++)
      derivative(x[i])[j] = xa[i][j];
  }
  tape->interpret_adjoint();
  for (size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < l; j++)
      xa[i][j] = derivative(x[i])[j];
  }
  for (size_t i = 0; i < m; i++) {
    for (std::size_t j = 0; j < l; j++)
      ya[i][j] = derivative(y[i])[j];
  }
}
