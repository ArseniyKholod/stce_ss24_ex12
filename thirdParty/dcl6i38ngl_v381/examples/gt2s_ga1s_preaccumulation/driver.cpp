/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include <cmath>
#include "dco.hpp"

using namespace std;

using namespace dco;

typedef gt1s<double> DCO_BASE_MODE;
typedef DCO_BASE_MODE::type DCO_BASE_TYPE;
typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "f.hpp"

void driver(const int n, double& xv, double& xt2, double& xa1, double& xt2a1) {
  DCO_TYPE x;
  passive_value(x) = xv;
  derivative(value(x)) = xt2;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  tape->register_variable(x);
  DCO_TYPE x_in = x;
  auto p = tape->get_position();
  f(n, x);
  cerr << "ts=" << dco::size_of(tape) << "B" << endl;
  xv = passive_value(x);
  xt2 = derivative(value(x));
  value(derivative(x)) = xa1;
  derivative(derivative(x)) = xt2a1;
  tape->interpret_adjoint_and_reset_to(p);
  xa1 = value(derivative(x_in));
  xt2a1 = derivative(derivative(x_in));
}
