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

void driver(const vector<double>& xv, vector<double>& xa, vector<double>& yv, vector<double>& ya, vector<double>& yp) {
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  size_t n = xv.size(), m = yv.size();
  vector<DCO_TYPE> x(begin(xv), end(xv)), y(m);
  tape->register_variable(x);
  f(x, y);

  std::vector<double> py(n);

  typedef gbcp<DCO_TYPE>::type DCO_GBCP_TYPE;
  auto const& px = create_gbcp<vector<DCO_GBCP_TYPE>>(x);
  f(px, py);

  for (size_t i = 0; i < m; i++) {
    tape->register_output_variable(y[i]);
    yv[i] = value(y[i]);
    derivative(y[i]) = ya[i];
  }
  for (size_t i = 0; i < n; i++)
    derivative(x[i]) = xa[i];

  tape->write_to_dot();
  tape->interpret_adjoint();
  for (size_t i = 0; i < n; i++)
    xa[i] = derivative(x[i]);
  for (size_t i = 0; i < m; i++)
    ya[i] = derivative(y[i]);
  for (size_t i = 0; i < m; i++)
    yp[i] = py[i];
}
