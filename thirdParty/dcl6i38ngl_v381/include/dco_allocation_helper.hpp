/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#include "dco_configuration.hpp"

namespace dco {

#ifdef _MSC_VER
inline mem_long_t get_total_system_memory() {

#ifndef DCO_SKIP_WINDOWS_H_INCLUDE
  MEMORYSTATUSEX status;
  status.dwLength = sizeof(status);
  GlobalMemoryStatusEx(&status);
  return status.ullTotalPhys;
#else
  return 0;
#endif
}
#else
inline mem_long_t get_total_system_memory() {
  mem_long_t pages = static_cast<mem_long_t>(sysconf(_SC_PHYS_PAGES));
  mem_long_t page_size = static_cast<mem_long_t>(sysconf(_SC_PAGE_SIZE));

  mem_long_t addressable_system_mem;
  if (std::numeric_limits<mem_long_t>::max() / pages < page_size) {
    addressable_system_mem = std::numeric_limits<mem_long_t>::max();
  } else {
    addressable_system_mem = static_cast<mem_long_t>(pages) * static_cast<mem_long_t>(page_size);
  }
  return addressable_system_mem;
}
#endif

inline std::string get_from_env(const std::string name) {
  std::string ret = "";
#if defined(_WIN32)
  size_t requiredSize;
  getenv_s(&requiredSize, NULL, 0, name.c_str());
  if (requiredSize != 0) {
    char* retstr = static_cast<char*>(malloc(requiredSize * sizeof(char)));
    getenv_s(&requiredSize, retstr, requiredSize, name.c_str());
    ret = std::string(retstr);
    free(retstr);
  }
#else
  char* retstr = getenv(name.c_str());
  if (retstr)
    ret = std::string(retstr);
#endif
  return ret;
}

inline size_t get_allocation_size(size_t req_size) {

  if (req_size > 0) {
    DCO_LOG(logDEBUG1) << "get_allocation_size: user given size = " << req_size << ". Returning.";
    return req_size;
  }

  double mem_ratio = 0.1;
  std::string retstr = get_from_env("DCO_MEM_RATIO");
  if (retstr != "")
    mem_ratio = atof(retstr.c_str());
  DCO_LOG(logDEBUG1) << "DCO_MEM_RATIO =  " << mem_ratio;

  mem_long_t physical_memory_size = get_total_system_memory();
  DCO_LOG(logDEBUG1) << "get_allocation_size: physical memory size = " << physical_memory_size;
  physical_memory_size = static_cast<mem_long_t>(static_cast<double>(physical_memory_size) * mem_ratio);
  DCO_LOG(logDEBUG1) << "get_allocation_size: physical memory size scaled by mem_ratio = " << physical_memory_size;

  size_t max_addressable_size = std::numeric_limits<size_t>::max();
  DCO_LOG(logDEBUG1) << "get_allocation_size: max addressable size = " << max_addressable_size;

  retstr = get_from_env("DCO_MAX_ALLOCATION");

  mem_long_t max_allocation_size_in_k = physical_memory_size / 1024;

  if (physical_memory_size == 0 && retstr == "") {
    throw dco::exception::create<std::runtime_error>("Executable compiled with DCO_SKIP_WINDOWS_H_INCLUDE;"
                                                     "i.e. no way of retrieving default tape allocation size "
                                                     "from physical memory size. Please export environment "
                                                     "variable DCO_MAX_ALLOCATION instead.",
                                                     __FILE__, __LINE__);
  }

  if (retstr != "") {
    max_allocation_size_in_k = static_cast<mem_long_t>(atof(retstr.c_str()));
    DCO_LOG(logDEBUG1) << "get_allocation_size: DCO_MAX_ALLOCATION =  " << max_allocation_size_in_k << "K";
  }
  DCO_LOG(logDEBUG1) << "get_allocation_size: max allocation size = " << max_allocation_size_in_k << "K";

  size_t allocation_size = static_cast<size_t>(
      std::min(max_allocation_size_in_k, static_cast<mem_long_t>(max_addressable_size) / 1024) * 1024);
  DCO_LOG(logDEBUG1) << "get_allocation_size: allocation size = " << allocation_size / 1024 << "K";

  return allocation_size;
}
} // namespace dco
