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

int f(int n) {
  if (n == 0)
    return 1;
  return n * f(n - 1);
}

void l(int c, int r, int b) {
  static int j = 0;
  if (c > 1 && r >= 0) {
    int ll = f(c + r) / (f(c) * f(r));
    cout << j++ << ": c=" << c << "; "
         << "r=" << r << "; "
         << "b=" << b << "; "
         << "l=" << ll << "; "
         << "cp=" << b + ll << "; " << endl;
    l(c - 1, r, b + ll);
    l(c, r - 1, b);
    j--;
  }
}

int main() {
  int c = 5;
  int r = 3;
  l(c, r - 1, 0);
}
