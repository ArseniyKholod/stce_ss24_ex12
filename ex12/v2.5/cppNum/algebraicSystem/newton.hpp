// info@stce.rwth-aachen.de
#pragma once

#include "system.hpp"
#include "cppNum/algebraicSystem/solver.hpp"
#include "solver.hpp"

namespace as {

  template<typename T, typename SYSTEM_T=system_t, typename DATA_T=void, typename LINEAR_SOLVER_T=la::lu_solver_t<T>>
  class newton_solver_t : public solver_t<T,SYSTEM_T,DATA_T> {
      using solver_t<T,SYSTEM_T,DATA_T>::_states;
      using solver_t<T,SYSTEM_T,DATA_T>::_parameters;
      using solver_t<T,SYSTEM_T,DATA_T>::_accuracy;
      using solver_t<T,SYSTEM_T,DATA_T>::_trace;
      using solver_t<T,SYSTEM_T,DATA_T>::_data_p;
    public:
      newton_solver_t(const T& accuracy, const DATA_T* const data_p=nullptr, bool trace=false);
      la::vector_t<T> run(la::vector_t<T> x, const la::vector_t<T>& p);
  };

}

#include "cppNum/derivative.hpp"

namespace as {
  template<typename T, typename SYSTEM_T, typename DATA_T, typename LINEAR_SOLVER_T>
  newton_solver_t<T,SYSTEM_T,DATA_T,LINEAR_SOLVER_T>::newton_solver_t(const T& accuracy, const DATA_T* const data_p, bool trace) : solver_t<T,SYSTEM_T,DATA_T>(accuracy,trace,data_p) {}

  template<typename T, typename SYSTEM_T, typename DATA_T, typename LINEAR_SOLVER_T>
  la::vector_t<T> newton_solver_t<T,SYSTEM_T,DATA_T,LINEAR_SOLVER_T>::run(la::vector_t<T> x, const la::vector_t<T> &p) {
    if (_trace) { _states.push_back(x); _parameters=p; }
    la::vector_t<T> residual=SYSTEM_T::F(x,p,_data_p);
    do {
      x+=LINEAR_SOLVER_T::run(derivative_t::dFdx<SYSTEM_T,T,DATA_T>(x,p,_data_p),-residual);
      if (_trace) _states.push_back(x);
      residual=SYSTEM_T::F(x,p,_data_p);
    } while (residual.norm()>_accuracy);
    return x;
  }
}
