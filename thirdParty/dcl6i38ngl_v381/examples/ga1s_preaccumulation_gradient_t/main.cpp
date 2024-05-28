/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

//** This example shows how to add a custom gradient directly into the
//** tape. No callback is introduced (see ga1s_external_manual for how
//** to use callbacks instead). This interface works exactly the same
//** for higher order modes.
#include "dco.hpp"

//** Custom multiplication function. Returns x*y.
template <typename T>
//** This implementation is only valid for adjoint dco types.
typename std::enable_if<dco::mode<T>::is_adjoint_type, T>::type my_multiply(T const& x, T const& y) {

  using value_t = typename dco::mode<T>::value_t;

  //** Declare active variable and assign it to function value,
  //** i.e. the multiplication result. The function evaluation should
  //** only use value_t data; avoid active computation. If you need to
  //** use active data, switch the tape off first.
  T z = dco::value(x) * dco::value(y);

  //** Compute partial derivatives (dz/dx and dz/dy). Again, only
  //** value_t data should be used.
  value_t dzdx = dco::value(y);
  value_t dzdy = dco::value(x);

  //** Create local gradient builder; the constructor activates z
  //** (i.e. assigns new tape index).
  typename dco::mode<T>::local_gradient_t z_gradient_builder(z);

  //** Gradient entries are passed element by element. First argument
  //** is the active input variable, second is the partial derivative
  //** w.r.t. that input. The second argument is of type value_t.
  z_gradient_builder.put(x, dzdx);
  z_gradient_builder.put(y, dzdy);

  return z;
}

int main() {
  //** Run first order adjoint. Usual driver code.
  using mode_t = dco::ga1s<double>;
  using type = mode_t::type;

  dco::smart_tape_ptr_t<mode_t> tape;

  //** Declare, initialize, register inputs.
  type x(1.0), y(2.0);
  tape->register_variable(x);
  tape->register_variable(y);

  //** Record tape.
  type z = my_multiply(x, y);

  //** Register output, seed adjoint, interpret tape.
  tape->register_output_variable(z);
  dco::derivative(z) = 1.0;
  tape->interpret_adjoint();

  std::cout << "dz/dx = " << dco::derivative(x) << std::endl;
  std::cout << "dz/dy = " << dco::derivative(y) << std::endl;
}
