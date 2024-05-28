/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include "dco.hpp"

using namespace std;
using namespace dco;

typedef ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;
typedef DCO_TAPE_TYPE::iterator_t DCO_TAPE_POSITION_TYPE;

#include "f.hpp"

void driver(const double& pv, double& pa, double& xv, const double& xa) {
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  DCO_TYPE x = xv, p = pv;
  tape->register_variable(p);
  f(p, x);
  cerr << "ts=" << dco::size_of(tape) << "B" << endl;
  xv = value(x);
  tape->register_output_variable(x);
  derivative(x) = xa;
  tape->interpret_adjoint();
  pa = derivative(p);
}
