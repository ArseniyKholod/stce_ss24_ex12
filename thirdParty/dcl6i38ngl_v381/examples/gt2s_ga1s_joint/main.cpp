/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

// This example demostrates basic checkpointing with dco/c++ for
// second-order adjoint mode. It computes the first- and second-order
// derivative of the scalar function y = f(x) with a standard dco/c++
// second-order adjoint driver (see main). f(x) consists of three
// parts. First, it computes a cosine of the input, then it calls g,
// and afterwards is computes cosine of the output of g and returns
// that. g is checkpointed in g_make_gap.

// The example is almost identical to the first-order one. Only the
// driver code changes (see main). Especially all the checkpointing
// logic doesn't have to change.

#include "dco.hpp"

// g_make_gap uses dco/c++'s checkpointing interface; see
// implementation below.
template <typename T> T g_make_gap(T const& x);

// Implementation of g. It returns the sine of the input.
template <typename T> T g(T const& x) {
  T y = sin(x);
  return y;
}

// Implementation of y = f(x), which we differentiate in main.
template <typename T> T f(T const& x) {
  // Computation preceding function g. Tape is written for this part.
  T y = cos(x);
  // This function will write a checkpoint and computes g only
  // passively, without taping.
  y = g_make_gap(y);
  // Computation succeeding function g. Tape is written for this part.
  y = cos(y);
  return y;
}

int main() {
  // Using second-order adjoint mode (forward-over-reverse).
  using mode_t = dco::ga1s<dco::gt1s<double>::type>;
  using type = mode_t::type;

  // Input variable.
  type x = 2.1;

  dco::smart_tape_ptr_t<mode_t> tape;
  tape->register_variable(x);

  // Seeding tangent direction. This is required in addition compared
  // to the first-order code.
  dco::derivative(dco::value(x)) = 1.0;

  // Record tape for f; this includes the checkpoint.
  type y = f(x);

  tape->register_output_variable(y);

  dco::derivative(y) = 1.0;
  // Interpret the tape. This will call the fill_gap function (see
  // implementation of g_make_gap below).
  tape->interpret_adjoint();

  std::cout << "y = " << y << std::endl;
  std::cout << "x_{(1)} = " << dco::derivative(x) << std::endl;
  // This is additional information compared to the first-order code.
  std::cout << "y^{(2)} = " << dco::derivative(dco::value(y)) << std::endl;
  std::cout << "x_{(1)}^{(2)} = " << dco::derivative(dco::derivative(x)) << std::endl;
}

// Creates a checkpoint and inserts the callback into the tape.
template <typename T> T g_make_gap(T const& x) {
  // Get tape pointer to tape x is registered in (tape).
  auto tape = dco::tape(x);

  // Compute the value of g with doubles (return type of
  // dco::value(x)). The active variable y is initialized with the
  // passive value.
  T y = g(dco::value(x));
  // Register variable y, since it is the output of g_make_gap;
  // succeeding computation is supposed to be taped, i.e. y is an
  // input to everything which comes later.
  tape->register_variable(y);

  // Callback. This lambda captures by copy ([=]) all accessed
  // data. In this case x and y. This callback is called during tape
  // interpretation, so all accessed data needs to be available
  // during tape interpretation time. The tape is used to fill the
  // gap.
  auto fill_gap = [=]() {
    // This is the current position of the tape.
    auto p = tape->get_position();
    // Record tape for g, since it's now executed with active types.
    // The captured input x is used directly.
    T yl = g(x);
    // The local output yl now lives in the tape (has a tape index).
    // It gets seeded with the adjoint of the original output
    // y. dco::derivative(y) holds the adjoint of the computation in
    // f which succeeded the call of g_make_gap.
    dco::derivative(yl) = dco::derivative(y);
    // Propagate adjoints into the inputs x and reset the tape we've
    // recorded in this callback.
    tape->interpret_adjoint_and_reset_to(p);
  };
  // We move the lambda into the tape as callback. No copy required,
  // since fill_gap is not required outside the tape.
  tape->insert_callback(std::move(fill_gap));

  return y;
}
