#include "cppNum/derivative.hpp"

namespace ae {

  template<typename T, typename DATA_T, typename EQUATION_T>
  newton_solver_t<T,DATA_T,EQUATION_T>::newton_solver_t(const T& accuracy, const DATA_T* const data_p, bool trace) : solver_t<T,DATA_T,EQUATION_T>(accuracy,trace,data_p) {}

  template<typename T, typename DATA_T, typename EQUATION_T>
  T newton_solver_t<T,DATA_T,EQUATION_T>::run(T x, const T &p) {
    using namespace std;
    T residual=EQUATION_T::f(x,p,_data_p);
    if (_trace) { _parameter=p; _states.push_back(x); }
    do {
      x-=residual/derivative_t::dfdx<EQUATION_T,T,DATA_T>(x,p,_data_p);
      residual=EQUATION_T::f(x,p,_data_p);
      if (_trace) _states.push_back(x);
    } while (fabs(residual)>_accuracy);
    return x;
  }

}
