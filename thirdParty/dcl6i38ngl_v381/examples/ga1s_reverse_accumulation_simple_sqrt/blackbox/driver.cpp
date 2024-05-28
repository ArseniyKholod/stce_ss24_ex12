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

#include "my_sqrt.hpp"

void driver(const double& p, double& pa1, double& x, double& xa1) {
  dco::smart_tape_ptr_t<dco::ga1s<double>> tape;
  dco::ga1s<double>::type a1s_x = x, a1s_p = p;
  tape->register_variable(a1s_p);
  my_sqrt(a1s_p, a1s_x);
  my_sqrt(a1s_p, a1s_x);
  cerr << "tape size=" << dco::size_of(tape) << endl;
  dco::value(a1s_x) = x;
  tape->register_output_variable(a1s_x);
  dco::derivative(a1s_x) = xa1;
  tape->interpret_adjoint();
  pa1 = dco::derivative(a1s_p);
}
