// info@stce.rwth-aachen.de
#pragma once
#include "cppNum/approximation.hpp"
#include "equation.hpp"
#include <string>

namespace ae {
  // abstract base class for solvers of generic algebraic equations
  template<typename T, typename EQUATION_T=equation_t>
  class solver_t : public approximation_t<T> {
    protected:
      using approximation_t<T>::_states; using approximation_t<T>::_parameter;   
    public:
      solver_t(const T& accuracy, bool trace);
      virtual T run(T x, const T& p)=0;
      const std::vector<T>& get_states() const;
      void plot(const std::string& filename) const;
  };
}

#include "solver.cpp" 
