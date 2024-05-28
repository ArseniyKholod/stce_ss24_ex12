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

// #include "my_sqrt.hpp"
#include "my_exp.hpp"

void driver(const double& p, double& pa1, double& x, double& xa1) {
  my_exp(p, x);
  dco::smart_tape_ptr_t<dco::ga1s<double>> tape;
  dco::ga1s<double>::type a1s_x = x, a1s_p = p;
  tape->register_variable(a1s_p);
  dco::ga1s<double>::tape_t::iterator_t i = tape->get_position();
  my_exp(a1s_p, a1s_x);
  cerr << "size of global tape = " << dco::size_of(tape) << endl;
  x = dco::value(a1s_x);
  tape->register_output_variable(a1s_x);
  double xa1_old = xa1 + 1;
  while (std::fabs(xa1_old - xa1) > 1e-15) {
    xa1_old = xa1;
    dco::derivative(a1s_x) = xa1;
    tape->interpret_adjoint();
    tape->zero_adjoints_to(i);
    xa1 = dco::derivative(a1s_x);
    cout << ".";
  }
  pa1 = dco::derivative(a1s_p);
}
