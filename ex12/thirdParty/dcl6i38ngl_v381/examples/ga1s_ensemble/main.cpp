/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
using namespace std;

#include "driver.hpp"

int main() {
  cout.precision(5);
  int n = 10;
  int m = 10;
  double xv = 2.1, xa = 0.0, yv, ya = 1.0;
  driver(n, m, xv, xa, yv, ya);
  cout << "y=" << yv << endl;
  cout << "x_{(1)}=" << xa << endl;
}
