// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/approximation.hpp"

namespace as {

  template<typename T, typename SYSTEM_T, typename DATA_T>
  class solver_t : public approximation_t<T> {
    protected:
      using approximation_t<T>::_states;
      using approximation_t<T>::_parameters;
      const DATA_T* const _data_p;
    public:
      solver_t(const T& accuracy, bool trace, const DATA_T* const data_p);
      virtual la::vector_t<T> run(la::vector_t<T> x, const la::vector_t<T>& p)=0;
      void plot(const std::string& filename, int i) const;
      void plot(const std::string& filename, int i, int j) const;
  };

}

#include <fstream>
#include "cppNum/exceptions/logic_error.hpp"
#include <exception>
#include <iostream>

namespace as {

  template<typename T, typename SYSTEM_T, typename DATA_T>
  solver_t<T,SYSTEM_T,DATA_T>::solver_t(const T& accuracy, bool trace, const DATA_T* const data_p) : approximation_t<T>(accuracy, trace), _data_p(data_p) {}
  
  template<typename T, typename SYSTEM_T, typename DATA_T>
  void solver_t<T,SYSTEM_T,DATA_T>::plot(const std::string& filename, int i) const {
    try{
      std::ofstream ofs(filename);
      //check if requested state exists
      if(i < 0 || i >= _states[0].rows())
        throw(ex::logic_error("State outside range is requested."));
      for (const auto& state : _states)
        ofs << state(i) << " 0\n" << state(i) << ' ' 
            << SYSTEM_T::F(state,_parameters,_data_p)(i)
	    << std::endl;
      ofs.close();
    }
    catch(const std::exception & e){
      std::cerr<<"std:exception was caught in solver_t::plot with following message:"<<std::endl<<e.what()<<std::endl;
    }
    catch(...){
      std::cerr<<"Exception of unknown type was caught in solver_t::plot."<<std::endl;
    }
  }

  template<typename T, typename SYSTEM_T, typename DATA_T>
  void solver_t<T,SYSTEM_T,DATA_T>::plot(const std::string& filename, int i, int j) const {
    try{
      std::ofstream ofs(filename);
      //check if requested states exist
      if(i < 0 || i >= _states[0].rows() || j < 0 || j >= _states[0].rows())
        throw(ex::logic_error("State outside range is requested."));
      for (const auto& state : _states)
        ofs << state(i) << ' ' << state(j) << " 0\n" 
            << state(i) << ' ' << state(j) << ' ' 
            << SYSTEM_T::F(state,_parameters,_data_p).norm()
	    << std::endl;
      ofs.close();
    }
    catch(const std::exception & e){
      std::cerr<<"std:exception was caught in solver_t::plot with following message:"<<std::endl<<e.what()<<std::endl;
    }
    catch(...){
      std::cerr<<"Exception of unknown type was caught in solver_t::plot."<<std::endl;
    }
  }

}
