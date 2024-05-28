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
  double p = 5, pt2 = 1, pa1 = 0, pa1t2 = 0, x = 1, xt2 = 0, xa1 = 1, xa1t2 = 0;
  driver(p, pt2, pa1, pa1t2, x, xt2, xa1, xa1t2);
  cout << "x=" << x << endl;
  cout << "x^{(2)}=" << xt2 << endl;
  cout << "p_{(1)}=" << pa1 << endl;
  cout << "p_{(1)}^{(2)}=" << pa1t2 << endl;
}
