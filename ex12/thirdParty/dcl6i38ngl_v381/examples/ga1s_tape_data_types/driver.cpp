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

typedef long double DCO_VALUE_TYPE;
typedef double DCO_PARTIAL_TYPE;
typedef float DCO_ADJOINT_TYPE;
typedef ga1s<DCO_VALUE_TYPE, DCO_PARTIAL_TYPE, DCO_ADJOINT_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "f.hpp"

void driver(const vector<double>& xv, vector<double>& xa, vector<double>& yv, vector<double>& ya) {
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  size_t n = xv.size(), m = yv.size();
  vector<DCO_TYPE> x(n), y(m);
  for (size_t i = 0; i < n; i++) {
    x[i] = xv[i];
    tape->register_variable(x[i]);
  }
  f(x, y);
  for (size_t i = 0; i < m; i++) {
    tape->register_output_variable(y[i]);
    yv[i] = static_cast<float>(value(y[i]));
    derivative(y[i]) = static_cast<float>(ya[i]);
  }
  for (size_t i = 0; i < n; i++)
    derivative(x[i]) = static_cast<float>(xa[i]);

  tape->write_to_dot();
  tape->interpret_adjoint();
  xa = derivative(x);
  ya = derivative(y);
}
