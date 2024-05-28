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

template <typename AD_TYPE>
void g(int from, int to,
       int stride, // max number of consecutive tapings
       AD_TYPE& x) {
  if (to - from > stride) {
    g(from, from + (to - from) / 2, stride, x);
    g(from + (to - from) / 2, to, stride, x);
  } else
    for (int i = from; i < to; i++)
      x = sin(x);
}
