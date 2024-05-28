/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include <iostream>
#include <cmath>
#include <omp.h>

#include "dco.hpp"
typedef dco::ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

#include "f.h"

using namespace std;

void driver(float& adjoint_float, double& adjoint_double) {
  const int n = 1000;
  double x0 = 1;
  vector<DCO_TYPE> p(n, 1);
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  for (int i = 0; i < n; i++)
    tape->register_variable(p[i]);
  DCO_TYPE x = x0;
  euler(0, n, x, p);
  tape->register_output_variable(x);

  omp_set_num_threads(2);

#pragma omp parallel
  {
    switch (omp_get_thread_num()) {
    case 0: {
      dco::adjoint_vector<DCO_TAPE_TYPE, float> av_float(tape);
      dco::derivative(x, av_float) = 1;
      av_float.interpret_adjoint();
      adjoint_float = dco::derivative(p[n / 2], av_float);
      break;
    }
    case 1: {
      dco::adjoint_vector<DCO_TAPE_TYPE, double> av_double(tape);
      dco::derivative(x, av_double) = 1;
      av_double.interpret_adjoint();
      adjoint_double = dco::derivative(p[n / 2], av_double);
    }
    default: {
    }
    }
  }
}
