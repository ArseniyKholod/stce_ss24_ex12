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
typedef ga1sm<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "f.hpp"

void driver(const int n, const int m, const double& xv, double& xa1, double& yv, const double& ya1) {
  DCO_TYPE x = xv, y;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  tape->register_variable(x);
  f(n, m, x, y);
  cerr << "tape size=" << dco::size_of(tape) << "B" << endl;
  yv = value(y);
  tape->register_output_variable(y);
  derivative(y) = ya1;
  derivative(x) = xa1;
  tape->interpret_adjoint();
  xa1 = derivative(x);
}
