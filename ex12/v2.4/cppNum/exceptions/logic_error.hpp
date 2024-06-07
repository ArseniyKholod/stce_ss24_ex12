#pragma once
#include "cppNum_exception.hpp"
#include <string>

/// An exception class to handle logical errors
class logic_error: public cppNum_exception {
  protected:
    /// Error message
    std::string what_arg;
  public:
    /// Constructor to initialize error message
    logic_error(const std::string&);
    /// Copy constructor
    logic_error(const logic_error&);
};

logic_error::logic_error(const std::string& what_arg) : what_arg(what_arg){}
logic_error::logic_error(const logic_error& err){
  what_arg = err.what_arg;
}
