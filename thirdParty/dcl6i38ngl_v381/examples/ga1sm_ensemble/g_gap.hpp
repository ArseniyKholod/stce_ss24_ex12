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
#include "g.hpp"

void g_make_gap(int m, const DCO_TYPE& x, const double& r, DCO_TYPE& yg) {
  static int c = 1;
  int ts = c++;

  g(m, dco::value(x), r, dco::value(yg));
  dco::tape(x)->register_variable(yg);

  auto fill_gap = [=]() {
    auto p = dco::tape(x)->get_position();
    DCO_TYPE y;
    g(m, x, r, y);
    cerr << "ts" << ts << "=" << dco::size_of(dco::tape(x)) << "B" << endl;
    dco::derivative(y) = dco::derivative(yg);
    dco::tape(x)->interpret_adjoint_and_reset_to(p);
  };
  dco::tape(x)->insert_callback(std::move(fill_gap));
}
