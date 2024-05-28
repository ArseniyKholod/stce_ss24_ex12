// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/approximation.hpp"
#include <string>

namespace as {

  template<typename T>
  class solver_t : public approximation_t<T> {
    protected:
      using approximation_t<T>::_states;
      using approximation_t<T>::_parameters;
    public:
      solver_t(const T& accuracy, bool trace);
      virtual la::vector_t<T> run(la::vector_t<T> x, const la::vector_t<T>& p)=0;
      void plot(const std::string& filename, int i, int j) const;
  };

}

#include <fstream>

namespace as {

  template<typename T>
  solver_t<T>::solver_t(const T& accuracy, bool trace) : approximation_t<T>(accuracy,trace) {}
  
  template<typename T>
  void solver_t<T>::plot(const std::string& filename, int i, int j) const {
    std::ofstream ofs(filename);
    for (const auto& state : _states)
      ofs << state(i) << ' ' << state(j) << " 0\n" 
          << state(i) << ' ' << state(j) << ' ' 
          << system_t::F(state,_parameters).norm()
	  << std::endl;
    ofs.close();
  }

}
