// info@stce.rwth-aachen.de

#pragma once

#include <vector>
#include <string>

template<typename T>
class iteration_t {
  protected:
    T _parameter;
    std::vector<T> _states;
    bool _trace;
  public:
    iteration_t(bool trace);
    virtual void plot(const std::string&) const=0;
};

#include "iteration.cpp"
