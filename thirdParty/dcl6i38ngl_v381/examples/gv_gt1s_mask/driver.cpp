/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <vector>
#include "dco.hpp"

using namespace std;
using namespace dco;

#include "f.hpp"

static const unsigned long VECTOR_SIZE = 8;
typedef gv<double, VECTOR_SIZE> DCO_BASE_MODE;
typedef DCO_BASE_MODE::type DCO_BASE_TYPE;
typedef gt1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;

void driver(const vector<double>& xv, vector<double>& xt, vector<double>& yv, vector<double>& yt) {
  const size_t n = xv.size();
  DCO_TYPE vec_x, vec_y;
  for (auto range : dco::subranges<VECTOR_SIZE>(n)) {
    for (auto i : range) {
      value(vec_x)[i.sub_index] = xv[i.global_index];
      derivative(vec_x)[i.sub_index] = xt[i.global_index];
    }
    f(vec_x, vec_y);
    for (auto i : range) {
      yv[i.global_index] = value(vec_y)[i.sub_index];
      yt[i.global_index] = derivative(vec_y)[i.sub_index];
    }
  }
}
