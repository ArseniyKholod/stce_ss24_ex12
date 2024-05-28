/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>

#include "driver.h"
using namespace std;

int main() {
  float adjoint_float;
  double adjoint_double;

  driver(adjoint_float, adjoint_double);

  cout << "float "
       << "dx/dp=" << adjoint_float << endl;
  cout << "double "
       << "dx/dp=" << adjoint_double << endl;
}
