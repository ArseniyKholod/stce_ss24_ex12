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

typedef double DCO_BASE_TYPE;
typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

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
    yv[i] = value(y[i]);
    derivative(y[i]) = ya[i];
  }
  for (size_t i = 0; i < n; i++)
    derivative(x[i]) = xa[i];
  tape->interpret_adjoint();
  for (size_t i = 0; i < n; i++)
    xa[i] = derivative(x[i]);
  for (size_t i = 0; i < m; i++)
    ya[i] = derivative(y[i]);
}

#include <cfloat>

void fd_driver(const vector<double>& xv, vector<double>& xa, vector<double>& xa1t2x, vector<double>& yv,
               vector<double>& yt2x, vector<double>& ya) {
  size_t n = xv.size(), m = yv.size();
  vector<double> h(n), xap(n), xvp(n), yvp(m), yap(m);
  for (size_t i = 0; i < m; i++)
    yap[i] = ya[i];
  for (size_t i = 0; i < n; i++) {
    xap[i] = xa[i];
    h[i] = (xv[i] == 0) ? sqrt(DBL_EPSILON) : sqrt(DBL_EPSILON) * abs(xv[i]);
    xvp[i] = xv[i] + h[i];
  }
  driver(xv, xa, yv, ya);
  driver(xvp, xap, yvp, yap);
  for (size_t i = 0; i < m; i++)
    yt2x[i] = (yvp[i] - yv[i]) / h[i];
  for (size_t i = 0; i < n; i++)
    xa1t2x[i] = (xap[i] - xa[i]) / h[i];
}
