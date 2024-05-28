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

typedef ga1s<double> DCO_BASE_MODE;
typedef DCO_BASE_MODE::type DCO_BASE_TYPE;
typedef DCO_BASE_MODE::tape_t DCO_BASE_TAPE_TYPE;
typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

#include "f.hpp"

void driver(const vector<double>& xv, vector<double>& xa2, vector<double>& xa1, vector<double>& xa1a2,
            vector<double>& yv, vector<double>& ya2, vector<double>& ya1, vector<double>& ya1a2) {

  dco::smart_tape_ptr_t<DCO_BASE_MODE> tape_base;
  dco::smart_tape_ptr_t<DCO_MODE> tape;

  const size_t n = xv.size(), m = yv.size();
  vector<DCO_TYPE> x(n), y(m);

  for (size_t j = 0; j < n; j++) {
    x[j] = xv[j];
    tape_base->register_variable(value(x[j]));
    tape->register_variable(x[j]);
  }

  f(x, y);

  for (size_t j = 0; j < m; j++) {
    derivative(y[j]) = ya1[j];
    tape_base->register_variable(derivative(y[j]));
  }

  tape->interpret_adjoint();

  for (size_t j = 0; j < n; j++) {
    xa1[j] = value(derivative(x[j]));
    derivative(derivative(x[j])) = xa1a2[j];
  }
  for (size_t j = 0; j < m; j++) {
    derivative(value(y[j])) = ya2[j];
  }
  tape_base->interpret_adjoint();

  for (size_t j = 0; j < n; j++) {
    xa2[j] = derivative(value(x[j]));
  }

  for (size_t j = 0; j < m; j++) {
    yv[j] = value(value(y[j]));
    ya1a2[j] = derivative(derivative(y[j]));
  }
}
