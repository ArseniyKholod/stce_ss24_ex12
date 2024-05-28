/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <vector>
using namespace std;

template <typename T>
void f(const vector<T>& x, // active inputs
       T& y                // active outputs
) {
  T v = tan(x[0] * x[3]);
  T w = x[1] - v;
  y = x[2] * v / w;
}
