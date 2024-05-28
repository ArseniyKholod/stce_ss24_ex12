#include "cppNum/derivative.hpp"
#include "cppNum/algebraicEquation/newton.hpp"
namespace co {
  template<typename T>
  newton_minimizer_t<T>::newton_minimizer_t(const T& accuracy, bool trace) : minimizer_t<T>(accuracy,trace) {}

  template<typename T>
  template<typename ae_T>
  ae_T newton_minimizer_t<T>::f(const ae_T &x, const ae_T& p) {
    return derivative_t::dfdx<objective_t,ae_T>(x,p);
  }

  template<typename T>
  T newton_minimizer_t<T>::run(T x, const T &p) {
    ae::newton_solver_t<T,newton_minimizer_t<T>> ae_solver(_accuracy,_trace);
    x=ae_solver.run(x,p);
    if (_trace) { _states=ae_solver.get_states(); _parameter=p; }
    return x;
  }
}
