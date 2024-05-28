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
  double x = .1, p = 0.5, xa1 = 1, pa1 = 0;
  driver(p, pa1, x, xa1);
  cout.precision(5);
  cout << "x=" << x << endl;
  cout << "p_{(1)}=" << pa1 << endl;
}
