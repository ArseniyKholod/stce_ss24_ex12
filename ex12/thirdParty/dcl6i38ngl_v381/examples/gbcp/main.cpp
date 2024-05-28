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
  const size_t n = 4, m = 2;
  cout.precision(5);
  vector<double> xv(n), xa(n), yv(m), ya(m), yp(m);
  for (size_t i = 0; i < n; i++) {
    xv[i] = 1;
    xa[i] = 1;
  }
  for (size_t i = 0; i < m; i++)
    ya[i] = 1;
  driver(xv, xa, yv, ya, yp);
  for (size_t i = 0; i < m; i++)
    cout << "y[" << i << "]=" << yv[i] << endl;
  for (size_t i = 0; i < m; i++)
    cout << "yp[" << i << "]=" << yp[i] << endl;
  for (size_t i = 0; i < n; i++)
    cout << "x_{(1)}[" << i << "]=" << xa[i] << endl;
}
