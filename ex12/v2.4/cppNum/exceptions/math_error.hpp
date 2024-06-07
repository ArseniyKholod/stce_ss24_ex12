#pragma once
#include "cppNum_exception.hpp"
#include <string>

/// An exception class to handle mathematical errors
class math_error: public cppNum_exception {
  protected:
    /// Error message
    std::string what_arg;
  public:
    /// Constructor to initialize error message
    math_error(const std::string&);
    /// Copy constructor
    math_error(const math_error&);
};

math_error::math_error(const std::string& what_arg) : what_arg(what_arg){}
math_error::math_error(const math_error& err){
  what_arg = err.what_arg;
}

