/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <vector>
#include <iostream>
#include "dco.hpp"
using namespace std;
using namespace dco;
#include "../x22.hpp"

template <typename T> void driver(const vector<T>& xv, T& yv, vector<T>& g, vector<vector<T>>& H) {
  typedef typename gt1s<T>::type DCO_BASE_TYPE;
  typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
  typedef typename DCO_MODE::type DCO_TYPE;
  size_t n = xv.size();
  vector<DCO_TYPE> x(n);
  DCO_TYPE y;

  dco::smart_tape_ptr_t<DCO_MODE> tape;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      tape->register_variable(x[j]);
      passive_value(x[j]) = xv[j];
      derivative(value(x[j])) = 0;
    }
    derivative(value(x[i])) = 1;
    f(x, y);
    tape->register_output_variable(y);
    yv = passive_value(y);
    g[i] = derivative(value(y));
    value(derivative(y)) = 1;
    tape->interpret_adjoint();
    for (size_t j = 0; j < n; j++)
      H[i][j] = derivative(derivative(x[j]));
    tape->reset();
  }
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
