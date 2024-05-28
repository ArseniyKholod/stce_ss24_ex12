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

void driver(const int n, const int m, double& x, double& xt2, double& xa1, double& xt2a1) {
  DCO_TYPE t2s_a1s_x;
  DCO_BASE_TYPE v;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  v = value(t2s_a1s_x);
  value(v) = x;
  derivative(v) = xt2;
  value(t2s_a1s_x) = v;
  tape->register_variable(t2s_a1s_x);
  DCO_TYPE x_indep = t2s_a1s_x;
  auto p = tape->get_position();
  f(n, m, t2s_a1s_x);
  cerr << "base=" << dco::size_of(tape) << "B" << endl;
  v = derivative(t2s_a1s_x);
  value(v) = xa1;
  derivative(v) = xt2a1;
  derivative(t2s_a1s_x) = v;
  tape->interpret_adjoint_and_reset_to(p);
  v = value(t2s_a1s_x);
  x = value(v);
  xt2 = derivative(v);
  v = derivative(x_indep);
  xa1 = value(v);
  xt2a1 = derivative(v);
}
