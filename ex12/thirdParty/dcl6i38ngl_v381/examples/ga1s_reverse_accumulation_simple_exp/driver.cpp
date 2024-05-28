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

#include "my_exp.hpp"

void driver(const double& p, double& pa1, double& x, double& xa1) {
  my_exp(p, x);
  dco::smart_tape_ptr_t<dco::ga1s<double>> tape;
  dco::ga1s<double>::type a1s_x = x, a1s_p = p;
  tape->register_variable(a1s_p);
  auto i = tape->get_position();
  tape->register_variable(a1s_x);
  dco::ga1s<double>::type x_indep = a1s_x;
  my_exp(a1s_p, a1s_x);
  // cout << dco::size_of(tape) << endl;
  x = dco::value(a1s_x);
  tape->register_output_variable(a1s_x);
  double xa1_old = xa1 + 1;
  int j = 0;
  while (std::fabs(xa1_old - xa1) > 1e-5) {
    j++;
    xa1_old = xa1;
    dco::derivative(a1s_x) = xa1;
    tape->interpret_adjoint();
    xa1 = dco::derivative(x_indep);
    tape->zero_adjoints_to(i);
  }
  cout << j << " adjoint iterations" << endl;
  pa1 = dco::derivative(a1s_p);
}
