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
using namespace std;

#include "driver.hpp"

int main() {
  cout.precision(5);
  const int n = 4, m = 2;
  vector<double> x(n), y(m);
  vector<vector<double>> J(m, x);
  for (int i = 0; i < n; i++)
    x[i] = 1;
  a1s_driver(x, y, J);
  for (int i = 0; i < m; i++)
    cout << "y[" << i << "]=" << y[i] << endl;
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++)
      cout << "F'[" << j << "][" << i << "]=" << J[j][i] << endl;
}
