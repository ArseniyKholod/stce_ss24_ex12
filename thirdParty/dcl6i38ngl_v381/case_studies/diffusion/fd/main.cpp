/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cfloat>

#include "../include/f.hpp"
using namespace std;

int main(int argc, char* argv[]) {
  cout.precision(5);
  if (argc < 3) {
    cerr << "2 parameters expected:" << endl
         << "  1. number of spatial finite difference grid points" << endl
         << "  2. number of implicit Euler steps" << endl
         << "  3. if third parameter given, print output" << endl;
    return EXIT_FAILURE;
  }
  size_t n = atoi(argv[1]), m = atoi(argv[2]);
  vector<double> c(n);
  for (size_t i = 0; i < n; i++)
    c[i] = 0.01;
  vector<double> T(n);
  for (size_t i = 0; i < n - 1; i++)
    T[i] = 300.;
  T[n - 1] = 1700.;
  ifstream ifs("O.txt");
  vector<double> O(n);
  for (size_t i = 0; i < n; i++)
    ifs >> O[i];
  vector<double> dvdc(n, 0), cph(n, 0), cmh(n, 0);
  double vmh;
  double vph;
  for (size_t j = 0; j < n; j++) {
    double h = (c[j] == 0) ? sqrt(DBL_EPSILON) : sqrt(DBL_EPSILON) * std::abs(c[j]);
    for (size_t i = 0; i < n; i++)
      cmh[i] = c[i];
    for (size_t i = 0; i < n - 1; i++)
      T[i] = 300.;
    T[n - 1] = 1700.;
    cmh[j] -= h;
    f(cmh, m, T, O, vmh);
    for (size_t i = 0; i < n; i++)
      cph[i] = c[i];
    for (size_t i = 0; i < n - 1; i++)
      T[i] = 300.;
    T[n - 1] = 1700.;
    cph[j] += h;
    f(cph, m, T, O, vph);
    dvdc[j] = (vph - vmh) / (2 * h);
  }
  cout.precision(5);
  if (argc == 4) {
    for (size_t i = 0; i < n; i++)
      cout << "dvdc[" << i << "]=" << dvdc[i] << endl;
  } else {
    cout << "Finite differences too unstable to give reproducible numbers on various platforms." << endl
         << "Run with third parameter to print derivative results." << endl;
  }
}
