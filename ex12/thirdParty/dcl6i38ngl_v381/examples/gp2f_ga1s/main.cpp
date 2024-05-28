/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

//** Example for second-order sparsity pattern computation in tapeless
//** forward mode based on underlying adjoint evaluation.
#include "dco.hpp"

//** The function we analyse (tridiagonal Jacobian pattern).
template <typename T> std::vector<T> f(std::vector<T> const& x, std::size_t m) {

  std::vector<T> y(m);
  for (std::size_t i = 0; i < y.size(); i++) {
    y[i] = (i != 0 ? x[i - 1] : 1) * x[i] * (i != y.size() - 1 ? x[i + 1] : 1);
  }
  return y;
}

std::vector<double> driver(std::vector<double> const& px, std::size_t m) {

  //** We use forward pattern mode based on underlying adjoint mode.
  using mode_t = dco::ga1s<dco::gp1f<double>::type>;
  using type = mode_t::type;

  std::vector<type> x(begin(px), end(px)), y;
  dco::smart_tape_ptr_t<mode_t> tape;

  tape->register_variable(x);
  //** We assume the pattern vector length (mode_t::p1f_size) is
  //** larger than x.size(), i.e. we propagate all dependency
  //** directions at the same time.
  for (std::size_t i = 0; i < x.size(); i++) {
    dco::derivative(dco::value(x[i]))[i] = true;
  }

  //** Record function into tape.
  y = f(x, m);

  std::cout << "Jacobian sparsity pattern:" << std::endl;
  for (std::size_t j = 0; j < m; j++) {
    std::cout << " |";
    for (std::size_t i = 0; i < x.size(); i++) {
      if (dco::derivative(dco::value(y[j]))[i])
        std::cout << "* ";
      else
        std::cout << "  ";
    }
    std::cout << "|" << std::endl;
  }
  std::cout << "Hessian sparsity pattern tensor:" << std::endl;

  for (std::size_t k = 0; k < px.size(); ++k) {
    dco::derivative(y[k]) = 1.0;

    //** Propagate dependency information for seeded adjoint
    //** direction.
    tape->interpret_adjoint();

    for (std::size_t j = 0; j < x.size(); j++) {
      for (std::size_t i = 0; i < x.size(); i++) {
        if (dco::derivative(dco::derivative(x[i]))[j])
          std::cout << i << " " << j << " " << k << std::endl;
      }
    }
    tape->zero_adjoints();
  }
  return dco::value(dco::value(y));
}

int main() {
  const std::size_t n = 4, m = 4;

  std::vector<double> x(n, 1.2);

  auto y = driver(x, m);

  std::cout << "y = [";
  for (auto const& yi : y) {
    std::cout << yi << " ";
  }
  std::cout << "]" << std::endl;
}
