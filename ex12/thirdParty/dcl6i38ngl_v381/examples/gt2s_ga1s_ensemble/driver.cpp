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

typedef gt1s<double> DCO_BASE_MODE;
typedef DCO_BASE_MODE::type DCO_BASE_TYPE;
typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;
typedef DCO_TAPE_TYPE::iterator_t DCO_TAPE_POSITION_TYPE;

#include "f.hpp"

void driver(const int n, const int m, const double& xv, const double& xt2, double& xa1, double& xa1t2, double& yv,
            double& yt2, const double& ya1, const double& ya1t2) {
  DCO_TYPE x = xv, y;
  derivative(value(x)) = xt2;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  tape->register_variable(x);
  DCO_TAPE_POSITION_TYPE p = tape->get_position();
  f(n, m, x, y);
  cerr << "base=" << dco::size_of(tape) << "B" << endl;
  yv = passive_value(y);
  yt2 = derivative(value(y));
  tape->register_output_variable(y);
  value(derivative(y)) = ya1;
  derivative(derivative(y)) = ya1t2;
  value(derivative(x)) = xa1;
  derivative(derivative(x)) = xa1t2;
  tape->interpret_adjoint_and_reset_to(p);
  xa1 = value(derivative(x));
  xa1t2 = derivative(derivative(x));
}
