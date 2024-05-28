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

#include "my_exp.hpp"

void driver(const double& p, double& pa1, double& x, double& xa1) {
  dco::smart_tape_ptr_t<ga1s<double>> tape;
  ga1s<double>::type a1s_x = x, a1s_p = p;
  tape->register_variable(a1s_p);
  my_exp(a1s_p, a1s_x);
  my_exp(a1s_p, a1s_x);
  cerr << "tape size=" << dco::size_of(tape) << endl;
  x = value(a1s_x);
  tape->register_output_variable(a1s_x);
  derivative(a1s_x) = xa1;
  tape->interpret_adjoint();
  pa1 = derivative(a1s_p);
}
