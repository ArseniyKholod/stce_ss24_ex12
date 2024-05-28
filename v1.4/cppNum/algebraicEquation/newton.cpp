#include "cppNum/derivative.hpp"

namespace ae {
  template<typename T, typename EQUATION_T>
  newton_solver_t<T,EQUATION_T>::newton_solver_t(const T& accuracy, bool trace) 
    : solver_t<T, EQUATION_T>(accuracy,trace) {}

  template<typename T, typename EQUATION_T>
  T newton_solver_t<T,EQUATION_T>::run(T x, const T &p) {
    using namespace std;
    if (_trace) { _states.push_back(x); _parameter=p; }
    T residual=EQUATION_T::f(x,p);
    do {
      x-=residual/derivative_t::dfdx<EQUATION_T,T>(x,p);
      if (_trace) _states.push_back(x);
      residual=EQUATION_T::f(x,p);
    } while (fabs(residual)>_accuracy);
    return x;
  }
}
