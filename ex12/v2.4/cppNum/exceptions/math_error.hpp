#pragma once
#include "cppNum_exception.hpp"
#include <string>

/// An exception class to handle mathematical errors
class math_error: public cppNum_exception {
  protected:
    /// Error message
    const char* what_arg;
  public:
    /// Constructor to initialize error message
    math_error(const char*);
    /// Copy constructor
    math_error(const math_error&);
    /// Returns explanatory string
    virtual const char* what() const noexcept{
      return what_arg;
    }
};

math_error::math_error(const char* what_arg) : what_arg(what_arg){}
math_error::math_error(const math_error& err){
  what_arg = err.what_arg;
}

