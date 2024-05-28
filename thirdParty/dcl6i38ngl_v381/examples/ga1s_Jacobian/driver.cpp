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

typedef double AD_BASE_TYPE;
typedef ga1s<AD_BASE_TYPE> AD_MODE;
typedef AD_MODE::type AD_TYPE;
typedef AD_MODE::tape_t AD_TAPE_TYPE;

#include "f.hpp"

void a1s_driver(const vector<double>& xv, vector<double>& yv, vector<vector<double>>& J) {
  dco::smart_tape_ptr_t<AD_MODE> tape;
  const size_t n = xv.size(), m = yv.size();
  vector<AD_TYPE> x(n), y(m);
  for (size_t i = 0; i < n; i++) {
    x[i] = xv[i];
    tape->register_variable(x[i]);
  }
  f(x, y);
  for (size_t i = 0; i < m; i++) {
    tape->register_output_variable(y[i]);
    yv[i] = value(y[i]);
  }

  for (size_t j = 0; j < m; j++) {
    derivative(y[j]) = 1;
    for (size_t i = 0; i < n; i++)
      derivative(x[i]) = 0;
    tape->interpret_adjoint();
    for (size_t i = 0; i < n; i++)
      J[j][i] = derivative(x[i]);
    tape->zero_adjoints();
  }
}
