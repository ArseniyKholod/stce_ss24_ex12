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

typedef dco::ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;
typedef DCO_TAPE_TYPE::iterator_t DCO_TAPE_POSITION_TYPE;

#include "f.hpp"

void driver(const int n, const int m, const double& xv, double& xa, double& yv, const double& ya) {
  DCO_TYPE x = xv, y;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  tape->register_variable(x);
  DCO_TAPE_POSITION_TYPE p = tape->get_position();
  f(n, m, x, y);
  cerr << "base=" << dco::size_of(tape) << "B" << endl;
  yv = value(y);
  tape->register_output_variable(y);
  derivative(y) = ya;
  derivative(x) = xa;
  tape->interpret_adjoint_and_reset_to(p);
  xa = derivative(x);
}
