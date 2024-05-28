// info@stce.rwth-aachen.de
#pragma once
#include "solver.hpp"
#include "equation.hpp"

namespace ae {
  template<typename T, typename EQUATION_T=equation_t>
  class newton_solver_t : public solver_t<T, EQUATION_T> {
     using solver_t<T, EQUATION_T>::_states; 
     using solver_t<T, EQUATION_T>::_parameter;
     using solver_t<T, EQUATION_T>::_accuracy; 
     using solver_t<T, EQUATION_T>::_trace;
    public:
      newton_solver_t(const T& accuracy, bool trace=false);
      T run(T x, const T& p);
  };
}
#include "newton.cpp"
