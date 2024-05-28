// info@stce.rwth-aachen.de
#pragma once

#include <vector>
#include <string>

/// abstract base for iterative algorithm enables recording of trace
template<typename T>
class iteration_t {
  protected:
    /// value of p
    T _parameter;
    /// values of all x visited during iteration
    std::vector<T> _states;
    /// tracing mode
    bool _trace;
  public:
    /// tracing mode set at time of construction
    iteration_t(bool trace);
    /// specialization requires output of recorded data into file for optional visualization
    virtual void plot(const std::string&) const=0;
};

#include "iteration.cpp" // implementations of member functions
