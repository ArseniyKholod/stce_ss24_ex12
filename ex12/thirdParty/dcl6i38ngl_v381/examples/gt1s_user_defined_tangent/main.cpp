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
  double x = 1, p = 5, xt1 = 0, pt1 = 1;
  driver(p, pt1, x, xt1);
  cout.precision(5);
  cout << "x=" << x << endl;
  cout << "x^{(1)}=" << xt1 << endl;
}
