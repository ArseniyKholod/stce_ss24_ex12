/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "driver.hpp"

int main() {
  cout.precision(5);
  int n = 10;
  int stride = 2;
  double x = 2.1, xa1 = 1.0;
  driver(n, stride, x, xa1);
  cout << "x=" << x << endl;
  cout << "x_{(1)}=" << xa1 << endl;
}
