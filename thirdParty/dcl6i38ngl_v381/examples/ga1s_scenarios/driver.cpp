/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "dco.hpp"
using namespace dco;
typedef double AD_BASE_TYPE;
typedef ga1s<AD_BASE_TYPE> AD_MODE;
typedef AD_MODE::type AD_TYPE;

void driver(int n, double& xv, double& xa, const double& pv, double& pa) {
  dco::smart_tape_ptr_t<AD_MODE> tape;
  AD_TYPE x = xv, p = pv;
  tape->register_variable(p);
  tape->register_variable(x);
  AD_TYPE x_in = x;

  auto p0 = tape->get_position();
  auto p1 = tape->get_position();

  for (int i = 0; i < n; i++) {
    x = sin(x * p);
    if (i == n / 2)
      p1 = tape->get_position();
  }

  tape->register_output_variable(x);
  derivative(x) = xa;
  derivative(p) = pa;
  tape->interpret_adjoint_to(p1);

  for (int i = 0; i < n; i++) {
    x = sin(x * p);
  }
  xv = value(x);

  tape->interpret_adjoint_to(p0);
  xa = derivative(x_in);
  pa = derivative(p);
}
