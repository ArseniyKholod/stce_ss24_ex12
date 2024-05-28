// info@stce.rwth-aachen.de
#pragma once
#include "solver.hpp"
#include "equation.hpp"

namespace ae {

  /// Newton method for solving algebraic equation f(x,p,aux_data)=0
  template<typename T, typename DATA_T=void, typename EQUATION_T=equation_t>
  class newton_solver_t : public solver_t<T,DATA_T,EQUATION_T> {
      using solver_t<T,DATA_T,EQUATION_T>::_accuracy;
      using solver_t<T,DATA_T,EQUATION_T>::_parameter;
      using solver_t<T,DATA_T,EQUATION_T>::_states;
      using solver_t<T,DATA_T,EQUATION_T>::_trace;
      using solver_t<T,DATA_T,EQUATION_T>::_data_p;
    public:
      /// accuracy, auxiliary data and tracing mode set at time of construction
      newton_solver_t(const T& accuracy, const DATA_T* const data_p=nullptr, bool trace=false);
      /// Newton method allowing side-effect-free overwrites of x
      T run(T x, const T& p);
  };

}
#include "newton.cpp"
