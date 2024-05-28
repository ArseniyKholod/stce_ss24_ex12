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

typedef dco::gt1s<double>::type DCO_BASE_TYPE;
typedef dco::ga1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

#include "f.h"

void driver() {
  const int n = 20, s = 10;
  const double x0 = 1;
  vector<DCO_TYPE> p(n, 1);
  vector<vector<double>> H(n, vector<double>(n, 0));
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  for (int i = 0; i < n; i++)
    tape->register_variable(p[i]);
  DCO_TAPE_TYPE::position_t tpos = tape->get_position();
  for (int j = 0; j < n; j++) {
    DCO_TYPE x = x0;
    dco::derivative(dco::value(p[j])) = 1;
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
    for (int i = 0; i < n; i++) {
      H[i][j] = dco::derivative(dco::derivative(p[i]));
      dco::derivative(p[i]) = 0;
    }
    tape->reset_to(tpos);
    dco::derivative(dco::value(p[j])) = 0;
  }
  for (int j = n / 2 - 1; j < n / 2 + 1; j++)
    for (int i = n / 2 - 1; i < n / 2 + 1; i++)
      cout << "ddx/dp[" << j << "]dp[" << i << "]=" << H[j][i] << endl;
}
