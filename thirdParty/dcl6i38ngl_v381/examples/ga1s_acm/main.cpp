/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

// joint reversal

#include <iostream>
#include <vector>
#include <stack>
#include "dco.hpp"

using namespace std;
typedef dco::ga1s<double> DCO_M;
typedef DCO_M::type DCO_T;
typedef dco::ACM::baseclass<DCO_M::tape_t, DCO_T> ACMBase;

template <typename AT, typename PT> struct MyACM : ACMBase {

  // passive context
  PT& dt; // UWE: why const?
  // argument checkpoint
  AT acp;

  MyACM(ACMBase::tape_t* tape, PT& dt) : ACMBase(tape), dt(dt) {}

  template <typename T> inline void g(T& x) { x += dt * sin(x); }

  void evaluate_primal() {
    AT x = input_value(0);
    g(x);
    output_value(0) = x;
  }

  void evaluate_augmented_primal() {
    acp = input_value(0);
    evaluate_primal();
  }

  void evaluate_adjoint() {
    auto tpos0 = this->get_tape()->get_position();
    DCO_T x = acp;
    this->get_tape()->register_variable(x);
    DCO_T x_in = x;
    auto tpos1 = this->get_tape()->get_position();
    g(x);
    this->get_tape()->register_output_variable(x);
    dco::derivative(x) = output_adjoint(0);
    this->get_tape()->interpret_adjoint_and_reset_to(tpos1);
    input_adjoint(0) = dco::derivative(x_in);
    cout << input_adjoint(0) << endl;
    this->get_tape()->reset_to(tpos0);
  }
};

int main() {
  cout.precision(5);
  dco::smart_tape_ptr_t<DCO_M> tape;
  DCO_T x = 1.0, y = 0;
  double dt = 1.0 / 3;
  tape->register_variable(x);
  DCO_T x_in = x;
  auto tpos = tape->get_position();
  // overloading on 1st third
  x += dt * sin(x);

  MyACM<double, double>* e = new MyACM<double, double>(tape, dt);
  e->register_input(x);
  e->register_output(y);
  tape->insert_ACM_object(e);
  e->evaluate_augmented_primal();
  // overloading on 3rd third
  y += dt * sin(y);
  tape->register_output_variable(y);
  cout << "y=" << dco::value(y) << endl;
  dco::derivative(y) = 1;
  tape->interpret_adjoint_and_reset_to(tpos);
  cout << "xa=" << dco::derivative(x_in) << endl;
}
