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
typedef gt1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "f.hpp"

void driver(const vector<double>& xv, vector<double>& xa2, vector<double>& xt1, vector<double>& xt1a2,
            vector<double>& yv, vector<double>& ya2, vector<double>& yt1, vector<double>& yt1a2) {
  dco::smart_tape_ptr_t<DCO_BASE_MODE> tape;
  const size_t n = xv.size(), m = yv.size();
  vector<DCO_TYPE> x(n), y(m);
  for (size_t i = 0; i < n; i++) {
    tape->register_variable(value(x[i]));
    tape->register_variable(derivative(x[i]));
    passive_value(x[i]) = xv[i];
    value(derivative(x[i])) = xt1[i];
  }
  f(x, y);
  for (size_t i = 0; i < n; i++) {
    derivative(value(x[i])) = xa2[i];
    derivative(derivative(x[i])) = xt1a2[i];
  }
  for (size_t i = 0; i < m; i++) {
    yv[i] = passive_value(y[i]);
    yt1[i] = value(derivative(y[i]));
    tape->register_output_variable(value(y[i]));
    tape->register_output_variable(derivative(y[i]));
    derivative(value(y[i])) = ya2[i];
    derivative(derivative(y[i])) = yt1a2[i];
  }
  tape->interpret_adjoint();
  for (size_t i = 0; i < n; i++) {
    xt1a2[i] = derivative(derivative(x[i]));
    xa2[i] = derivative(value(x[i]));
  }
  for (size_t i = 0; i < m; i++) {
    yt1a2[i] = derivative(derivative(y[i]));
    ya2[i] = derivative(value(y[i]));
  }
}
