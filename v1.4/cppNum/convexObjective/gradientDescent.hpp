// info@stce.rwth-aachen.de
#pragma once
#include "minimizer.hpp"

namespace co {

  /// gradient descent minimizer
  template<typename T>
  class gradientDescent_minimizer_t : public minimizer_t<T> {
      using minimizer_t<T>::_states;
      using minimizer_t<T>::_parameter;
      using minimizer_t<T>::_accuracy;
      using minimizer_t<T>::_trace;
    public:
      /// constructor sets accuracy and tracing mode
      gradientDescent_minimizer_t(const T& accuracy, bool trace=false);
      /// runs the method for given x and p while avoiding side-effects due to internal overwrites of x
      T run(T x, const T& p);
  };

}

#include "gradientDescent.cpp" // implementations of all member functions
