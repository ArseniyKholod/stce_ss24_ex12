/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#include "dco.hpp"

typedef dco::ga1s<double> DCO_MODE;
typedef DCO_MODE::type DCO_TYPE;
typedef DCO_MODE::tape_t DCO_TAPE_TYPE;

int main() {

  dco::smart_tape_ptr_t<DCO_MODE> tape;
  DCO_TYPE x(0.0);

  tape->register_variable(x);

  DCO_TYPE t = sqrt(x * x);
  (void)t; // unused...
  DCO_TYPE y = 2 * x;

  dco::derivative(y) = 1.0;
  tape->interpret_adjoint();

  std::cerr << "Adjoint of x without sparse interpretation: " << dco::derivative(x) << std::endl;

  tape->zero_adjoints();
  tape->sparse_interpret() = true;

  dco::derivative(y) = 1.0;
  tape->interpret_adjoint();

  std::cout << "Adjoint of x with sparse interpretation: " << dco::derivative(x) << std::endl;
}
