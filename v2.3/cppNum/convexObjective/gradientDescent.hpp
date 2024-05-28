// info@stce.rwth-aachen.de
#pragma once

#include "minimizer.hpp"
#include "cppNum/linearAlgebra.hpp"

namespace co {

  template<typename T>
  class gradientdescent_minimizer_t : public minimizer_t<T> {
      using approximation_t<T>::_states;
      using approximation_t<T>::_parameters;
      using approximation_t<T>::_accuracy;
      using approximation_t<T>::_trace;
    public:
      gradientdescent_minimizer_t(const T& accuracy, bool trace=false);
      la::vector_t<T> run(la::vector_t<T>, const la::vector_t<T>&);
  };

}

#include "objective.hpp"
#include "cppNum/derivative.hpp"

namespace co {

  template<typename T>
  gradientdescent_minimizer_t<T>::gradientdescent_minimizer_t(const T& accuracy, bool trace) : minimizer_t<T>(accuracy, trace) {}

  template<typename T>
  la::vector_t<T> gradientdescent_minimizer_t<T>::run(la::vector_t<T> x, const la::vector_t<T>& p) {
    T y=objective_t::f(x,p), y_prev;
    if (_trace) { _states.push_back(x); _parameters=p; }
    la::vector_t<T> dydx=derivative_t::dfdx<objective_t,T>(x,p);
    do {
      y_prev=y;
      double alpha=2.;
      while (y_prev<=y&&alpha>_accuracy) {
        la::vector_t<T> x_trial=x;
        alpha/=2.;
        x_trial-=alpha*dydx; 
        y=objective_t::f(x_trial,p);
      }
      x-=alpha*dydx;
      if (_trace) _states.push_back(x);
      dydx=derivative_t::dfdx<objective_t,T>(x,p);
    } while (dydx.norm()>_accuracy);
    return x;
  }

}
