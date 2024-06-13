// info@stce.rwth-aachen.de
#pragma once

#include "iteration.hpp"
#include <vector>
#include <exception>

template<typename T>
class evolution_t : public iteration_t<T> {
  protected:
    using iteration_t<T>::_states;
    std::vector<T> _times;
  public:
    evolution_t(bool trace);
    void plot(const std::string& filename, int i) const;
};

#include <fstream>
#include "cppNum/exceptions/logic_error.hpp"
#include <iostream>

template<typename T>
evolution_t<T>::evolution_t(bool trace) : iteration_t<T>(trace) {}

template<typename T>
void evolution_t<T>::plot(const std::string& filename, int i) const {
  try{
    std::ofstream ofs(filename);
    assert(_states.size()==_times.size());
    //check if requested state exists
      if(i < 0 || i >= _states[0].rows())
        throw(ex::logic_error("State outside range is requested."));
    for (size_t k=0; k<_times.size(); ++k)
      ofs << _times[k] << ' ' << _states[k](i) << std::endl;
  }
  catch(const std::exception & e){
    std::cerr<<"std:exception was caught in evolution_t::plot with following message:"<<std::endl<<e.what()<<std::endl;
  }
  catch(...){
    std::cerr<<"Exception of unknown type was caught in evolution_t::plot."<<std::endl;
  }

}
