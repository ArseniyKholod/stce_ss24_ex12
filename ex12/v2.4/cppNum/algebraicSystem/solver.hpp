// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/approximation.hpp"

namespace as {

  template<typename T, typename SYSTEM_T>
  class solver_t : public approximation_t<T> {
    protected:
      using approximation_t<T>::_states;
      using approximation_t<T>::_parameters;
    public:
      solver_t(const T& accuracy, bool trace);
      virtual la::vector_t<T> run(la::vector_t<T> x, const la::vector_t<T>& p)=0;
      void plot(const std::string& filename, int i) const;
      void plot(const std::string& filename, int i,int j) const;
  };

}

#include <fstream>

namespace as {

  template<typename T, typename SYSTEM_T>
  solver_t<T,SYSTEM_T>::solver_t(const T& accuracy, bool trace) : approximation_t<T>(accuracy, trace) {}
  
  template<typename T, typename SYSTEM_T>
  void solver_t<T,SYSTEM_T>::plot(const std::string& filename, int i) const {
    std::ofstream ofs(filename);
    for (const auto& state : _states)
      ofs << state(i) << " 0\n" << state(i) << ' ' 
          << SYSTEM_T::F(state,_parameters)(i)
	  << std::endl;
    ofs.close();
  }

  template<typename T, typename SYSTEM_T>
  void solver_t<T,SYSTEM_T>::plot(const std::string& filename, int i, int j) const {
    std::ofstream ofs(filename);
    for (const auto& state : _states)
      ofs << state(i) << ' ' << state(j) << " 0\n" 
          << state(i) << ' ' << state(j) << ' ' 
          << SYSTEM_T::F(state,_parameters).norm()
	  << std::endl;
    ofs.close();
  }

}
