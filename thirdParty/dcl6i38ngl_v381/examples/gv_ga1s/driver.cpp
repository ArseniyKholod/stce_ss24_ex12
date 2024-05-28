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
typedef ga1s<DCO_BASE_TYPE> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

void driver(const vector<double>& xv, vector<double>& xa, vector<double>& yv, vector<double>& ya) {
  dco::smart_tape_ptr_t<DCO_MODE> tape;

  const size_t n = xv.size();
  DCO_TYPE vec_x, vec_y;
  for (auto range : dco::subranges<VECTOR_SIZE>(n)) {
    for (auto i : range) {
      value(vec_x)[i.sub_index] = xv[i.global_index];
    }
    tape->register_variable(vec_x);
    f(vec_x, vec_y);
    tape->register_output_variable(vec_y);
    for (auto i : range) {
      yv[i.global_index] = value(vec_y)[i.sub_index];
      derivative(vec_y)[i.sub_index] = ya[i.global_index];
      derivative(vec_x)[i.sub_index] = xa[i.global_index];
    }
    tape->interpret_adjoint();
    for (auto i : range) {
      ya[i.global_index] = derivative(vec_y)[i.sub_index];
      xa[i.global_index] = derivative(vec_x)[i.sub_index];
    }
    tape->reset();
  }
}
