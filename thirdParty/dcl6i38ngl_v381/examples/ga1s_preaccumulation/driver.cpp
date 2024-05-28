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
typedef ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "f.hpp"

void driver(const int n, double& xv, double& xa) {
  DCO_TYPE x = xv;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  tape->register_variable(x);
  DCO_TYPE x_in = x;
  auto p = tape->get_position();
  f(n, x);
  cerr << "ts=" << dco::size_of(tape) << "B" << endl;
  derivative(x) = xa;
  tape->interpret_adjoint_and_reset_to(p);
  xv = value(x);
  xa = derivative(x_in);
}
