// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/linearAlgebra.hpp"
#include "minimizer.hpp"
#include "objective.hpp"

namespace co {

  template<typename T, typename LINEAR_SOLVER_T=la::llt_solver_t<T>>
  class newton_minimizer_t : public minimizer_t<T> {
      using approximation_t<T>::_states;
      using approximation_t<T>::_parameters;
      using approximation_t<T>::_accuracy;
      using approximation_t<T>::_trace;
    public:
      newton_minimizer_t(const T& accuracy, bool trace=false);
      la::vector_t<T> run(la::vector_t<T>, const la::vector_t<T>&);
      template <typename AS_T>
      static la::vector_t<AS_T> F(const la::vector_t<AS_T>& x, const la::vector_t<AS_T>& p);
      void plot(const std::string& filename, int i);
      void plot(const std::string& filename, int i, int j);
  };

}

#include "cppNum/derivative.hpp"
#include "cppNum/algebraicSystem/newton.hpp"
#include <iostream>
#include <exception>

namespace co {

  template<typename T, typename LINEAR_SOLVER_T>
  newton_minimizer_t<T,LINEAR_SOLVER_T>::newton_minimizer_t(const T& accuracy, bool trace) : minimizer_t<T>(accuracy, trace) {}

  template<typename T, typename LINEAR_SOLVER_T>
  template<typename AS_T>
  la::vector_t<AS_T> newton_minimizer_t<T,LINEAR_SOLVER_T>::F(const la::vector_t<AS_T> &x, const la::vector_t<AS_T>& p) {
    try{
      return derivative_t::dfdx<objective_t,AS_T>(x,p);
    }
    catch(...){
      std::cerr<<"Exception was caught in co::newton_minimizer_t::F, throw it further."<<std::endl;
      throw;
    }
  }

  template<typename T, typename LINEAR_SOLVER_T>
  la::vector_t<T> newton_minimizer_t<T,LINEAR_SOLVER_T>::run(la::vector_t<T> x, const la::vector_t<T> &p) {
    la::vector_t<T> x_initial(x);
    try{
      as::newton_solver_t<T,newton_minimizer_t<T>,LINEAR_SOLVER_T> as_solver(_accuracy,_trace);
      x=as_solver.run(x,p);
      if (_trace) { _states=as_solver.get_states(); _parameters=p; }
      return x;
    }
    catch(const std::exception & e){
      std::cerr<<"std:exception was caught in co::newton_minimizer_t::run with following message:"<<std::endl<<e.what()<<std::endl;
    }
    catch(...){
      std::cerr<<"Exception of unknown type was caught in co::newton_minimizer_t::run."<<std::endl;
    }
    std::cerr<<"co::newton_minimizer_t::run returns an initial value of x. Check the correctness of the input."<<std::endl;
    return x_initial;

  }

  template<typename T, typename LINEAR_SOLVER_T>
  void newton_minimizer_t<T,LINEAR_SOLVER_T>::plot(const std::string& filename, int i) {
    try{
      std::ofstream ofs(filename);
      //check if requested state exists
      if(i < 0 || i >= _states[0].rows())
        throw(ex::logic_error("State outside range is requested."));
      for (size_t k=0; k<_states.size(); ++k)
        ofs << _states[k](i) << ' ' << objective_t::f(_states[k],_parameters) << std::endl;
    }
    catch(const std::exception & e){
      std::cerr<<"std:exception was caught in co::newton_minimizer_t::plot with following message:"<<std::endl<<e.what()<<std::endl;
    }
    catch(...){
      std::cerr<<"Exception of unknown type was caught in co::newton_minimizer_t::plot."<<std::endl;
    }
  }

  template<typename T, typename LINEAR_SOLVER_T>
  void newton_minimizer_t<T,LINEAR_SOLVER_T>::plot(const std::string& filename, int i, int j) {
    try{
      std::ofstream ofs(filename);
      //check if requested states exist
      if(i < 0 || i >= _states[0].rows() || j < 0 || j >= _states[0].rows())
        throw(ex::logic_error("State outside range is requested."));
      for (size_t k=0; k<_states.size(); ++k) 
        ofs << _states[k](i) << ' ' << _states[k](j) << ' ' << objective_t::f(_states[k],_parameters) << std::endl;
    }
    catch(const std::exception & e){
      std::cerr<<"std:exception was caught in co::newton_minimizer_t::plot with following message:"<<std::endl<<e.what()<<std::endl;
    }
    catch(...){
      std::cerr<<"Exception of unknown type was caught in co::newton_minimizer_t::plot."<<std::endl;
    }
  }
}
