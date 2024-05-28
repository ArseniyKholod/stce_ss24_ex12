/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <vector>
#include <array>
#include "dco.hpp"

using namespace std;
#include "driver.hpp"

using namespace dco;
typedef ga1v<double, N> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "f.hpp"

void driver(const vector<double>& xv, vector<array<double, N>>& xa1, double& yv, array<double, N>& ya1) {
  size_t n = xv.size();
  vector<DCO_TYPE> x(n);
  vector<DCO_TYPE> x_in(n);
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  for (size_t i = 0; i < n; i++) {
    tape->register_variable(x[i]);
    value(x[i]) = xv[i];
    derivative(x[i]) = xa1[i];
    x_in[i] = x[i];
  }
  DCO_TYPE y;
  auto p = tape->get_position();
  f(x, y);
  cerr << "ts=" << dco::size_of(tape) << "B" << endl;
  yv = value(y);
  derivative(y) = ya1;

  //** The callback is implemented in vectorized fashion, not with
  //** scalars, see g_gap.hpp:21.
  tape->scalar_callback_mode() = false;

  tape->interpret_adjoint_and_reset_to(p);
  for (size_t i = 0; i < n; i++)
    xa1[i] = derivative(x_in[i]);
}
