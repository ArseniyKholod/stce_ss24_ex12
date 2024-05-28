#include "cppNum/derivative.hpp"

namespace ae {

  template<typename T>
  newton_solver_t<T>::newton_solver_t(const T& accuracy, bool trace) 
    : solver_t<T>(accuracy,trace) {}

  template<typename T>
  T newton_solver_t<T>::run(T x, const T &p) {
    using namespace std; // enable overloading of std::fabs outside of std::
    if (_trace) { _states.push_back(x); _parameter=p; }
    T residual=equation_t::f(x,p);
    do {
      x-=residual/derivative_t::dfdx<equation_t>(x,p);
      if (_trace) _states.push_back(x);
      residual=equation_t::f(x,p);
    } while (fabs(residual)>_accuracy);
    return x;
  }

}
