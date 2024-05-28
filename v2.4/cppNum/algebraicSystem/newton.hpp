// info@stce.rwth-aachen.de
#pragma once

#include "system.hpp"
#include "solver.hpp"

namespace as {

  template<typename T, typename SYSTEM_T=system_t, typename LINEAR_SOLVER_T=la::lu_solver_t<T>>
  class newton_solver_t : public solver_t<T,SYSTEM_T> {
      using solver_t<T,SYSTEM_T>::_states;
      using solver_t<T,SYSTEM_T>::_parameters;
      using solver_t<T,SYSTEM_T>::_accuracy;
      using solver_t<T,SYSTEM_T>::_trace;
    public:
      newton_solver_t(const T& accuray, bool trace=false);
      la::vector_t<T> run(la::vector_t<T> x, const la::vector_t<T>& p);
  };

}

#include "cppNum/derivative.hpp"

namespace as {
  template<typename T, typename SYSTEM_T, typename LINEAR_SOLVER_T>
  newton_solver_t<T,SYSTEM_T,LINEAR_SOLVER_T>::newton_solver_t(const T& accuracy,bool trace) : solver_t<T,SYSTEM_T>(accuracy,trace) {}

  template<typename T, typename SYSTEM_T, typename LINEAR_SOLVER_T>
  la::vector_t<T> newton_solver_t<T,SYSTEM_T,LINEAR_SOLVER_T>::run(la::vector_t<T> x, const la::vector_t<T> &p) {
    if (_trace) { _states.push_back(x); _parameters=p; }
    la::vector_t<T> residual=SYSTEM_T::F(x,p);
    do {
      x+=LINEAR_SOLVER_T::run(derivative_t::dFdx<SYSTEM_T,T>(x,p),-residual);
      if (_trace) _states.push_back(x);
      residual=SYSTEM_T::F(x,p);
    } while (residual.norm()>_accuracy);
    return x;
  }

}
