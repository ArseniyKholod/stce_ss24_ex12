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
#include <vector>
#include "dco.hpp"

using namespace std;

typedef dco::ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

#include "f.h"

void driver() {
  const int n = 20, s = 10;
  const double x0 = 1;
  vector<DCO_TYPE> p(n, 1);
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  for (int i = 0; i < n; i++)
    tape->register_variable(p[i]);
  DCO_TYPE x = x0;
  DCO_MODE::jacobian_preaccumulator_t jp(tape);
  for (int i = 0; i < n; i += s) {
    jp.start();
    euler(i, min(i + s, n), x, p);
    jp.register_output(x);
    jp.finish();
  }
  tape->register_output_variable(x);
  dco::derivative(x) = 1;
  tape->interpret_adjoint();
  for (int i = n / 2 - 3; i < n / 2 + 3; i++)
    cout << "dx/dp[" << i << "]=" << dco::derivative(p[i]) << endl;
}
