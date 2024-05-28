// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/linearAlgebra.hpp"
#include "minimizer.hpp"
#include "objective.hpp"

namespace co {

  template<typename T, typename LINEAR_SOLVER_T=la::llt_solver_t<T>>
  class newton_minimizer_t : public minimizer_t<T> {
      using approximation_t<T>::_states;
      using approximation_t<T>::_parameters;
      using approximation_t<T>::_accuracy;
      using approximation_t<T>::_trace;
    public:
      newton_minimizer_t(const T& accuracy, bool trace=false);
      la::vector_t<T> run(la::vector_t<T>, const la::vector_t<T>&);
      template <typename AS_T>
      static la::vector_t<AS_T> F(const la::vector_t<AS_T>& x, const la::vector_t<AS_T>& p);
      void plot(const std::string& filename, int i);
      void plot(const std::string& filename, int i, int j);
  };

}

#include "cppNum/derivative.hpp"
#include "cppNum/algebraicSystem/newton.hpp"

namespace co {

  template<typename T, typename LINEAR_SOLVER_T>
  newton_minimizer_t<T,LINEAR_SOLVER_T>::newton_minimizer_t(const T& accuracy, bool trace) : minimizer_t<T>(accuracy, trace) {}

  template<typename T, typename LINEAR_SOLVER_T>
  template<typename AS_T>
  la::vector_t<AS_T> newton_minimizer_t<T,LINEAR_SOLVER_T>::F(const la::vector_t<AS_T> &x, const la::vector_t<AS_T>& p) {
    return derivative_t::dfdx<objective_t,AS_T>(x,p);
  }

  template<typename T, typename LINEAR_SOLVER_T>
  la::vector_t<T> newton_minimizer_t<T,LINEAR_SOLVER_T>::run(la::vector_t<T> x, const la::vector_t<T> &p) {
    as::newton_solver_t<T,newton_minimizer_t<T>,LINEAR_SOLVER_T> as_solver(_accuracy,_trace);
    x=as_solver.run(x,p);
    if (_trace) { _states=as_solver.get_states(); _parameters=p; }
    return x;
  }

  template<typename T, typename LINEAR_SOLVER_T>
  void newton_minimizer_t<T,LINEAR_SOLVER_T>::plot(const std::string& filename, int i) {
    std::ofstream ofs(filename);
    for (size_t k=0; k<_states.size(); ++k) 
      ofs << _states[k](i) << ' ' << objective_t::f(_states[k],_parameters) << std::endl;
  }

  template<typename T, typename LINEAR_SOLVER_T>
  void newton_minimizer_t<T,LINEAR_SOLVER_T>::plot(const std::string& filename, int i, int j) {
    std::ofstream ofs(filename);
    for (size_t k=0; k<_states.size(); ++k) 
      ofs << _states[k](i) << ' ' << _states[k](j) << ' ' << objective_t::f(_states[k],_parameters) << std::endl;
  }

}
