// info@stce.rwth-aachen.de
#pragma once
#include "minimizer.hpp"
#include "objective.hpp"

namespace co {
  /// Newton method
  template<typename T>
  class newton_minimizer_t : public minimizer_t<T> {
      using minimizer_t<T>::_states; using minimizer_t<T>::_parameter;
      using minimizer_t<T>::_accuracy; using minimizer_t<T>::_trace;
    public:
      /// constructor sets accuracy and tracing mode
      newton_minimizer_t(const T& accuracy, bool trace=false);
      /// runs the method avoiding side effects due to internal overwrites of x
      T run(T x, const T& p);
      /// residual of first-order optimality condition (vanishing first derivative)
      template <typename ae_T> static ae_T f(const ae_T&, const ae_T&);
  };
}
#include "newton.cpp" 
