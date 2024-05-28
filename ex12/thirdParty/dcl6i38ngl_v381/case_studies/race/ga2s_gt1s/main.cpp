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
typedef gt1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

#include "../x22.hpp"

template <typename T> void driver(const vector<T>& xv, T& yv, vector<T>& g, vector<vector<T>>& h) {
  dco::smart_tape_ptr_t<DCO_BASE_MODE> tape;
  size_t n = xv.size();
  vector<DCO_TYPE> x(n), x_in(n);
  DCO_TYPE y;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      x[j] = xv[j];
      tape->register_variable(value(x[j]));
      tape->register_variable(derivative(x[j]));
      x_in[j] = x[j];
    }
    value(derivative(x[i])) = 1;
    f(x, y);
    tape->register_output_variable(value(y));
    tape->register_output_variable(derivative(y));
    derivative(derivative(y)) = 1;
    tape->interpret_adjoint();
    for (size_t j = 0; j < n; j++)
      h[j][i] = derivative(value(x_in[j]));
    tape->reset();
    g[i] = value(derivative(y));
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
