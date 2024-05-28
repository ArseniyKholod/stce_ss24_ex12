/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

#include "driver.hpp"

int main() {
  cout.precision(5);
  int n = 5;
  vector<double> x(n), xa1(n);
  double y = 0, ya1;
  for (int i = 0; i < n; i++) {
    x[i] = cos(double(i));
    xa1[i] = 0;
  }
  ya1 = 1;
  driver(x, xa1, y, ya1);
  cout << "y=" << y << endl;
  for (int i = 0; i < n; i++)
    cout << "x_{(1)}[" << i << "]=" << xa1[i] << endl;
}
