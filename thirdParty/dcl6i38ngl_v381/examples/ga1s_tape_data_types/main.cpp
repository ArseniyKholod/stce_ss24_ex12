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
  const int n = 4, m = 2;
  vector<double> xv(n), xa(n), yv(m), ya(m);
  for (int i = 0; i < n; i++) {
    xv[i] = 1;
    xa[i] = 1;
  }
  for (int i = 0; i < m; i++)
    ya[i] = 1;
  driver(xv, xa, yv, ya);
  cout.precision(5);
  for (int i = 0; i < m; i++)
    cout << "y[" << i << "]=" << yv[i] << endl;
  cout.precision(5);
  for (int i = 0; i < n; i++)
    cout << "x_{(1)}[" << i << "]=" << xa[i] << endl;
}
