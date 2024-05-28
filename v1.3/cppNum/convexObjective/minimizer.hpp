// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/approximation.hpp"
#include <string>

namespace co {

  /// abstract base class for minimization methods
  template<typename T>
  class minimizer_t : public approximation_t <T> {
    protected:
      using approximation_t<T>::_states;
      using approximation_t<T>::_parameter;
      /// tracing mode
      bool _trace;
    public:
      /// constructor sets accuracy and tracing mode
      minimizer_t(const T& accuracy, bool trace);
      /// writes record of iterations performed by minimizer to file with given name
      void plot(const std::string& filename) const;
  };

}

#include "minimizer.cpp" 
