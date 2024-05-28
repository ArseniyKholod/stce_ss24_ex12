/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include <cfloat>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <vector>
using namespace std;

#include "../x22.hpp"

template <typename T> void cfd_driver(const vector<T>& x, T& y, vector<T>& g) {
  size_t n = x.size();
  vector<T> x_ph(n), x_mh(n);
  T y_ph, y_mh;
  f(x, y);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++)
      x_ph[j] = x_mh[j] = x[j];
    T h = (x[i] == 0) ? sqrt(sqrt(DBL_EPSILON)) : sqrt(sqrt(DBL_EPSILON)) * std::abs(x[i]);
    x_ph[i] += h;
    f(x_ph, y_ph);
    x_mh[i] -= h;
    f(x_mh, y_mh);
    g[i] = (y_ph - y_mh) / (2 * h);
  }
}

template <typename T> void socfd_driver(const vector<T>& x, T& y, vector<T>& g, vector<vector<T>>& H) {
  size_t n = x.size();
  vector<T> x_ph(n), x_mh(n), g_ph(n), g_mh(n);
  T y_ph, y_mh;
  cfd_driver(x, y, g);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++)
      x_ph[j] = x_mh[j] = x[j];
    T h = (x[i] == 0) ? sqrt(sqrt(DBL_EPSILON)) : sqrt(sqrt(DBL_EPSILON)) * std::abs(x[i]);
    x_ph[i] += h;
    f(x_ph, y_ph);
    cfd_driver(x_ph, y_ph, g_ph);
    x_mh[i] -= h;
    cfd_driver(x_mh, y_mh, g_mh);
    for (size_t j = 0; j < n; j++)
      H[i][j] = (g_ph[j] - g_mh[j]) / (2 * h);
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
  socfd_driver(x, y, g, H);
  cout << y << endl;
  for (size_t i = 0; i < n; i++)
    cout << g[i] << endl;
  for (size_t i = 0; i < n; i++)
    for (size_t j = 0; j < n; j++)
      cout << H[i][j] << endl;
}
