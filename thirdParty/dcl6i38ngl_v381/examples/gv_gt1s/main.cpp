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
#include <cstdlib>
#include <cmath>
using namespace std;

#include "driver.hpp"

int main() {
  const int m = 12, n = 12;
  cout.precision(5);
  vector<double> xv(n), xt(n), yv(m), yt(m);
  for (int i = 0; i < n; i++) {
    xv[i] = sin(static_cast<double>(i + 1));
    xt[i] = 1;
  }
  driver(xv, xt, yv, yt);
  for (int i = 0; i < m; i++)
    cout << "y[" << i << "]=" << yv[i] << endl;
  for (int i = 0; i < n; i++)
    cout << "y^{(1)}[" << i << "]=" << yt[i] << endl;
}
