/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

// This example demostrates how to checkpoint a loop equidistantly.
// This algorithm can be used e.g., for evolutions. For mutually
// independent loop iterations, see the example "ga1s_ensemble".

#include <iostream>
#include <cmath>

#include "dco.hpp"

// Function that mimics an evolution.
template <typename T> void g(int n, T& x) {
  for (int i = 0; i < n; i++)
    x = sin(x);
}

// Creates a gap for a chunk of size n.
void g_make_gap(int n, dco::ga1s<double>::type& x) {
  using mode_t = dco::ga1s<double>;
  using type = mode_t::type;
  // Count the chunks/gaps used for printing tape sizes.
  static int gap_counter_helper = 1;
  int gap_counter = gap_counter_helper++;

  // Since we are overwritting x, x_in stores the reference
  // (tape index) to access the correct derivative.
  type x_in(x);
  // Compute x passively.
  g(n, dco::value(x));

  // Create a new tape entry for the output of function g.
  dco::tape(x_in)->register_variable(x);

  // For a detailed description of checkpointing see example ga1s_joint.
  auto fill_gap = [=]() {
    type x_tmp = x_in;
    auto p = dco::tape(x_in)->get_position();
    g(n, x_tmp);
    std::cerr << "size of tape after gap" << gap_counter << " = " << dco::size_of(dco::tape(x_in)) << "B" << std::endl;
    dco::derivative(x_tmp) = dco::derivative(x);
    dco::tape(x_in)->interpret_adjoint_and_reset_to(p);
  };

  dco::tape(x_in)->insert_callback(std::move(fill_gap));
}

// This function splits the loop in g in chunks of size m.
template <typename T> void equidistant_checkpointing(int n, int m, T& x) {
  for (int i = 0; i < n; i += m)
    g_make_gap(std::min(m, n - i), x);
}

int main() {
  int n = 10;
  int m = 2;
  // Using first-order adjoint mode.
  using mode_t = dco::ga1s<double>;
  using type = mode_t::type;
  std::cout.precision(5);
  // Input:
  type x = 2.1;

  dco::smart_tape_ptr_t<mode_t> tape;
  tape->register_variable(x);

  // For dco/c++ inputs must be read only. Since we are overwritting x, x_in stores
  // the reference (tape index) used to access the correct derivative.
  type x_in = x;
  auto pos = tape->get_position();

  // Original function we want to checkpoint below.
  //    g(n, x);
  // Record tape, checkpointing the loop in chunks of size m.
  equidistant_checkpointing(n, m, x);

  std::cerr << "base = " << dco::size_of(tape) << "B" << std::endl;
  // Seed the output adjoint.
  dco::derivative(x) = 1.0;
  tape->interpret_adjoint_and_reset_to(pos);

  // Print output value.
  std::cout << "x = " << dco::value(x) << std::endl;
  // Print derivative.
  std::cout << "dx = " << dco::derivative(x_in) << std::endl;
}
