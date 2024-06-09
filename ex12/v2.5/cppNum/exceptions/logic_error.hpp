#pragma once
#include "cppNum_exception.hpp"
#include <string>

namespace ex{
  /// An exception class to handle logical errors
  class logic_error: public cppNum_exception {
    protected:
      /// Error message
      const char* what_arg;
    public:
      /// Constructor to initialize error message
      logic_error(const char*);
      /// Copy constructor
      logic_error(const logic_error&);
      /// Returns explanatory string
      virtual const char* what() const noexcept{
        return what_arg;
      }
  };
  
  logic_error::logic_error(const char* what_arg) : what_arg(what_arg){}
  logic_error::logic_error(const logic_error& err){
    what_arg = err.what_arg;
  }
}
