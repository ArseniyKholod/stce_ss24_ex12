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

typedef dco::gt1s<double>::type DCO_BT;
typedef dco::ga1s<DCO_BT> DCO_M;
typedef DCO_M::type DCO_T;
typedef DCO_M::tape_t DCO_TAPE_T;

#include "f.h"

void driver() {
  const int n = 10;
  double x0 = 1;
  vector<DCO_T> p(n, 1);
  vector<vector<double>> H(n, vector<double>(n, 0));
  dco::smart_tape_ptr_t<DCO_M> tape;
  for (int i = 0; i < n; i++)
    tape->register_variable(p[i]);
  DCO_M::tape_t::iterator_t tpos = tape->get_position();
  DCO_T x;
  for (int i = 0; i < n; i++) {
    tape->reset_to(tpos);
    x = x0;
    dco::derivative(dco::value(p[i])) = 1;
    euler(0, n, x, p);
    tape->register_output_variable(x);
    dco::adjoint_vector<DCO_TAPE_T, DCO_BT, 1> av_double(tape);
    av_double.derivative(x) = 1;
    av_double.interpret_adjoint();
    for (int j = 0; j < n; j++) {
      H[j][i] = dco::derivative(av_double.derivative(p[j])[0]);
      av_double.derivative(p[j])[0] = 0;
    }
    dco::derivative(dco::value(p[i])) = 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cout << "ddx/dp[" << i << "]dp[" << j << "]=" << H[i][j] << endl;
}
