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

template <typename T> void ga1s_driver(const vector<T>& xv, T& yv, vector<T>& g) {
  typedef ga1s<T> DCO_MODE;
  typedef typename DCO_MODE::type DCO_TYPE;
  size_t n = xv.size();
  vector<DCO_TYPE> x(n);
  DCO_TYPE y;

  typename dco::smart_tape_ptr_t<DCO_MODE> tape;
  for (size_t j = 0; j < n; j++) {
    tape->register_variable(x[j]);
    value(x[j]) = xv[j];
  }
  f(x, y);
  tape->register_output_variable(y);
  yv = value(y);
  derivative(y) = 1;
  tape->interpret_adjoint();
  for (size_t j = 0; j < n; j++)
    g[j] = derivative(x[j]);
}

int main(int c, char* v[]) {
  assert(c == 2);
  (void)c;
  cout.precision(5);
  size_t n = atoi(v[1]);
  vector<double> x(n), g(n);
  double y;
  for (size_t i = 0; i < n; i++)
    x[i] = cos(double(i));
  ga1s_driver(x, y, g);
  cout << y << endl;
  for (size_t i = 0; i < n; i++)
    cout << g[i] << endl;
}
