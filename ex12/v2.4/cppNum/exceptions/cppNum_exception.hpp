#pragma once
#include <exception>

namespace ex{ 
  /// Abstract basic class for all cppNum exceptions
  class cppNum_exception: public std::exception{
    public:
    virtual const char* what() const noexcept =0;
  };
}
