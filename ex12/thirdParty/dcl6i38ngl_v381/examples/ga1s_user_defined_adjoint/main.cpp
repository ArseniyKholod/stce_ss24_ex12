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
  double xv = 1, pv = 5, xa = 1, pa = 0;
  driver(pv, pa, xv, xa);
  cout.precision(5);
  cout << "x=" << xv << endl;
  cout << "p_{(1)}=" << pa << endl;
}
