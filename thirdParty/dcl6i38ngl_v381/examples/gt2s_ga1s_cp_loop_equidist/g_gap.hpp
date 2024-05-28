/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "g.hpp"

void g_make_gap(int n, DCO_TYPE& xg) {
  static int c = 1;
  int ts = c++;

  DCO_TYPE xg_in(xg);

  g(n, dco::value(xg));
  dco::tape(xg_in)->register_variable(xg);

  auto fill_gap = [=]() {
    DCO_TYPE x = xg_in;
    auto p = dco::tape(xg_in)->get_position();
    g(n, x);
    cerr << "ts" << ts << "=" << dco::size_of(dco::tape(xg_in)) << "MB" << endl;
    dco::derivative(x) = dco::derivative(xg);
    dco::tape(xg_in)->interpret_adjoint_and_reset_to(p);
  };
  dco::tape(xg_in)->insert_callback(std::move(fill_gap));
}
