/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include <vector>
#include "dco.hpp"

using namespace std;
using namespace dco;

typedef ga1s<double> DCO_BASE_MODE;
typedef DCO_BASE_MODE::type DCO_BASE_TYPE;
typedef DCO_BASE_MODE::tape_t DCO_BASE_TAPE_TYPE;
typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

#include "../x22.hpp"

template <typename T> void driver(const vector<T>& xv, T& yv, vector<T>& g, vector<vector<T>>& h) {
  size_t n = xv.size();
  vector<DCO_TYPE> x(n), x_in(n);
  DCO_TYPE y;
  dco::smart_tape_ptr_t<DCO_BASE_MODE> tape_base;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  for (size_t j = 0; j < n; j++) {
    x[j] = xv[j];
    tape_base->register_variable(value(x[j]));
    tape->register_variable(x[j]);
    x_in[j] = x[j];
  }
  f(x, y);
  derivative(y) = 1.0;
  tape_base->register_variable(derivative(y));
  tape->interpret_adjoint();
  for (size_t j = 0; j < n; j++)
    g[j] = value(derivative(x_in[j]));
  for (size_t i = 0; i < n; i++) {
    derivative(derivative(x_in[i])) = 1;
    tape_base->interpret_adjoint();
    for (size_t j = 0; j < n; j++)
      h[i][j] = derivative(value(x_in[j]));
    tape_base->zero_adjoints();
  }
  yv = passive_value(y);
}

int main(int c, char* v[]) {
  assert(c == 2);
  (void)c;
  cout.precision(5);
  size_t n = atoi(v[1]);
  vector<vector<double>> H(n, vector<double>(n));
  vector<double> x(n), g(n);
  double y;
  for (size_t i = 0; i < n; i++)
    x[i] = cos(double(i));
  driver(x, y, g, H);
  cout << y << endl;
  for (size_t i = 0; i < n; i++)
    cout << g[i] << endl;
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      cout << H[i][j] << endl;
}
