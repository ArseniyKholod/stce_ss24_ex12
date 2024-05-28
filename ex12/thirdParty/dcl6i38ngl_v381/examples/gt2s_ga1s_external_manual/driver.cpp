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

typedef gt1s<double> DCO_BASE_MODE;
typedef DCO_BASE_MODE::type DCO_BASE_TYPE;
typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "f.hpp"

void driver(const vector<double>& xv, const vector<double>& xt2, vector<double>& xa1, vector<double>& xa1t2, double& yv,
            double& yt2, double& ya1, double& ya1t2) {
  dco::smart_tape_ptr_t<ga1s<DCO_BASE_TYPE>> tape;
  const size_t n = xv.size();
  vector<DCO_TYPE> x(n), x_in(n);
  DCO_TYPE y;
  for (size_t i = 0; i < n; i++) {
    tape->register_variable(x[i]);
    value(value(x[i])) = xv[i];
    derivative(value(x[i])) = xt2[i];
    x_in[i] = x[i];
  }
  auto p = tape->get_position();
  f(x, y);
  cerr << "ts=" << dco::size_of(tape) << "B" << endl;
  for (size_t i = 0; i < n; i++) {
    value(derivative(x_in[i])) = xa1[i];
    derivative(derivative(x_in[i])) = xa1t2[i];
  }
  yv = value(value(y));
  yt2 = derivative(value(y));
  tape->register_output_variable(y);
  value(derivative(y)) = ya1;
  derivative(derivative(y)) = ya1t2;
  tape->interpret_adjoint_and_reset_to(p);
  for (size_t i = 0; i < n; i++) {
    xa1[i] = value(derivative(x_in[i]));
    xa1t2[i] = derivative(derivative(x_in[i]));
  }
}
