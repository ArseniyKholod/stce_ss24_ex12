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

// #include "../include/f_residual_Jacobian_by_hand.hpp"
// #include "../include/f_residual_Jacobian_by_dco_dense.hpp"
#include "../include/f.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  cout.precision(5);
  if (argc != 3) {
    cerr << "2 parameters expected:" << endl
         << "  1. number of spatial finite difference grid points" << endl
         << "  2. number of implicit Euler steps" << endl;
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
  double v;
  f(c, m, T, O, v);
  cout << "v=" << v << endl;
}
