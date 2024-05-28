/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "dco.hpp"

using namespace std;
using namespace dco;

typedef ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;
typedef DCO_TAPE_TYPE::iterator_t DCO_TAPE_POSITION_TYPE;

#include "f.hpp"

void driver(const int n, const int stride, double& xv, double& xa1) {
  DCO_TYPE x = xv;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  tape->register_variable(x);
  DCO_TYPE x_in = x;

  f(n, stride, x);

  tape->register_output_variable(x);
  derivative(x) = 1;

  tape->interpret_adjoint();

  xv = value(x);
  xa1 = derivative(x_in);
}
