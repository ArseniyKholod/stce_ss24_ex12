// info@stce.rwth-aachen.de
#pragma once

#include <vector>
#include <string>

template<typename T>
class iteration_t {
  protected:
    std::vector<T> _states;
  public:
    virtual void plot(const std::string&) const=0;
};
