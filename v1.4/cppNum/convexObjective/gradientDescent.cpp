#include "objective.hpp"
#include "cppNum/derivative.hpp"

namespace co {

  template<typename T> // construction of base object
  gradientDescent_minimizer_t<T>::gradientDescent_minimizer_t(const T& accuracy, bool trace) : minimizer_t<T>(accuracy,trace) {}

  template<typename T> // no side-effects due to internal overwrites of x
  T gradientDescent_minimizer_t<T>::run(T x, const T& p) { 
    using namespace std; // enables potential overloading of fabs outside of std::
    T y=objective_t::f(x,p), y_prev;
    if (_trace) { // record trace
      _states.push_back(x); 
      _parameter=p; 
    } 
    T dydx=derivative_t::dfdx<objective_t,T>(x,p);
    do { // at least one descent step to establish dependence on x (and p)
      y_prev=y; 
      double alpha=2.; 
      while (y_prev<=y&&alpha>_accuracy) { // line search 
        T x_trial=x; 
        alpha/=2.; // half-splitting
        x_trial-=alpha*dydx; 
        y=objective_t::f(x_trial,p);
      }
      x-=alpha*dydx;
      if (_trace) _states.push_back(x);  // record trace
      dydx=derivative_t::dfdx<objective_t,T>(x,p);
    } while (fabs(dydx)>_accuracy);
    return x;
  }

}
