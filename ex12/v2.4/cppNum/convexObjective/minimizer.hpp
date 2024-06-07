// info@stce.rwth-aachen.de
#pragma once

#include "cppNum/approximation.hpp"
#include "cppNum/exceptions/logic_error.hpp"

namespace co {

  template<typename T>
  class minimizer_t : public approximation_t <T> {
    protected:
      using approximation_t<T>::_states;
      using approximation_t<T>::_parameters;
    public:
      minimizer_t(const T& accuracy, bool trace);
      void plot(const std::string& filename, int i) const;
      void plot(const std::string& filename, int i, int j) const;
  };

}

#include <fstream>
#include<filesystem>

namespace co {

  template<typename T>
  minimizer_t<T>::minimizer_t(const T& accuracy, bool trace) : approximation_t<T>(accuracy,trace) {}

  template<typename T>
  void minimizer_t<T>::plot(const std::string& filename, int i) const {
    //check if folder of the given filename exists
    std::filesystem::path file_path(filename);
    if(!std::filesystem::exists(file_path))
      throw(logic_error("File " + filename + " is impossible to open/create"));
    std::ofstream ofs(filename);
    //check if requested state exists
    if(i < 0 || i >= _states[0].rows())
      throw(logic_error("State outside the range is requested."));
    for (const auto& state : _states)
      ofs << state(i) << ' ' << objective_t::f(state,_parameters) << std::endl;
    ofs.close();
  }

  template<typename T>
  void minimizer_t<T>::plot(const std::string& filename, int i, int j) const {
    //check if folder of the given filename exists
    std::filesystem::path file_path(filename);
    if(!std::filesystem::exists(file_path))
      throw(logic_error("File " + filename + " is impossible to open/create")); 
    std::ofstream ofs(filename);
    //check if requested states exist
    if(i < 0 || i >= _states[0].rows() || j < 0 || j >= _states[0].rows())
      throw(logic_error("State outside the range is requested."));
    for (const auto& state : _states)
      ofs << state(i) << ' ' << state(j) << ' ' << objective_t::f(state,_parameters) << std::endl;
    ofs.close();
  }

}
