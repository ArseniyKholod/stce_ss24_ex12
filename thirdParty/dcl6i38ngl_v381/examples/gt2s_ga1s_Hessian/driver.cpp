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

#include "f.hpp"

void t2s_a1s_Hessian(const vector<double>& xv, double& yv, vector<vector<double>>& hessian) {
  typedef gt1s<double> DCO_BASE_MODE;
  typedef DCO_BASE_MODE::type DCO_BASE_TYPE;
  typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
  typedef DCO_MODE::type DCO_TYPE;

  dco::smart_tape_ptr_t<DCO_MODE> tape;

  const size_t n = xv.size();

  vector<DCO_TYPE> x(n);
  DCO_TYPE y;
  for (size_t i = 0; i < n; i++)
    x[i] = xv[i];

  for (size_t i = 0; i < n; i++) {

    for (size_t j = 0; j < n; j++)
      tape->register_variable(x[j]);

    derivative(value(x[i])) = 1.0;

    f(x, y);

    tape->register_output_variable(y);
    derivative(y) = 1.0;

    tape->interpret_adjoint();

    for (size_t j = 0; j <= i; ++j)
      hessian[i][j] = derivative(derivative(x[j]));

    derivative(value(x[i])) = 0.0;
    tape->reset();
  }

  yv = passive_value(y);
}

//--- reverse-over-reverse with ga1s<ga1s<double>::type>::type data
//--- type. see reverse-over-reverse section in Uwe's book
//--- p. 108. here are a bunch of things hidden one could talk about.
void a2s_a1s_Hessian(const vector<double>& xv, double& yv, vector<vector<double>>& hessian) {

  dco::smart_tape_ptr_t<ga1s<double>> tape_base;
  dco::smart_tape_ptr_t<ga1s<ga1s<double>::type>> tape;

  const size_t n = xv.size();

  vector<ga1s<ga1s<double>::type>::type> x(n);
  ga1s<ga1s<double>::type>::type y;
  for (size_t i = 0; i < n; i++)
    x[i] = xv[i];

  for (size_t j = 0; j < n; j++) {
    tape_base->register_variable(value(x[j]));
    tape->register_variable(x[j]);
  }

  f(x, y); // important thing: just one recording step.

  tape->register_output_variable(y);
  derivative(y) = 1.0;

  tape->interpret_adjoint();

  for (size_t i = 0; i < n; i++) {
    derivative(derivative(x[i])) = 1.0;
    tape_base->interpret_adjoint();

    for (size_t j = 0; j <= i; ++j)
      hessian[i][j] = derivative(value(x[j]));

    tape_base->zero_adjoints();
  }

  yv = passive_value(y);
}
