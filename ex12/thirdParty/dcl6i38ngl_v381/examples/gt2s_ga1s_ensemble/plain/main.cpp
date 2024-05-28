/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <cstdlib>
#include <cmath>
#include <iostream>
#include "dco.hpp"

using namespace std;
using namespace dco;

template <typename ATYPE, typename BTYPE> void f(const int m, const ATYPE& x, const BTYPE& r, ATYPE& y) {
  y = 0;
  for (int i = 0; i < m; i++)
    y += sin(x + r);
}

int main() {
  int n = 10;
  int m = 10;
  dco::smart_tape_ptr_t<ga1s<gt1s<double>::type>> tape;

  gt1s<double>::type v = 2.1;
  derivative(v) = 1;
  ga1s<gt1s<double>::type>::type x = v;
  ga1s<gt1s<double>::type>::type y = 0, sum = 0;
  tape->register_variable(x);

  double r;
  for (int i = 0; i < n; i++) {
    r = rand();
    f(m, x, r, y);
    sum += y;
  }
  y = sum / n;
  double max_tape_size = static_cast<double>(dco::size_of(tape));

  v = value(y);
  cout << "value=" << v << endl;
  v = 1;
  derivative(y) = v;
  tape->interpret_adjoint();
  v = derivative(x);
  cout << "adjoint=" << v << endl;
  r = derivative(v);
  cout << "second-order adjoint=" << r << endl;
  cerr << "tape size=" << max_tape_size / 1024. / 1024. << " mb" << endl;
}
