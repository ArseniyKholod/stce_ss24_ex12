/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "dco.hpp"

using namespace std;
using namespace dco;

typedef dco::ga1s_mod<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

#include "timestepping.hpp"

int main(int c, char* v[]) {
  int n = 10;
  if (c == 2) {
    n = atoi(v[1]);
  }

  DCO_TYPE x = 1.0, p = 1.0;
  dco::smart_tape_ptr_t<DCO_MODE> tape;
  tape->register_variable(p);

  f(n, x, p);

  dco::derivative(x) = 1.0;
  tape->interpret_adjoint();

  cerr << "size of internal adjoint vector = " << dco::size_of(tape, DCO_TAPE_TYPE::size_of_internal_adjoint_vector)
       << "b" << endl;
  cerr << "size of tape memory = " << dco::size_of(tape, DCO_TAPE_TYPE::size_of_stack) << "b" << endl;

  cout << "dp=" << dco::derivative(p) << endl;
}
