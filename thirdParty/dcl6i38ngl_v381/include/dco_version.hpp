/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once
#include <string>

#define DCO_VERSION_SHORT 3.8
#define DCO_VERSION 3.8.1
#define DCO_BRANCH
#define DCO_COMPATIBILITY_VERSION_BASE 360000

#define DCO_VERSION_MAJOR 3
#define DCO_VERSION_MINOR 8
#define DCO_VERSION_PATCH 1
#define DCO_VERSION_ALPHA 0

#if defined(DCO_CHUNK_TAPE) || defined(DCO_FILE_TAPE)
#define DCO_CHUNK_TAPE_N 1
#else
#define DCO_CHUNK_TAPE_N 0
#endif
#ifdef DCO_TAPE_USE_LONG_INT
#define DCO_TAPE_USE_LONG_INT_N 2
#else
#define DCO_TAPE_USE_LONG_INT_N 0
#endif
#ifdef DCO_TAPE_USE_INT64
#define DCO_TAPE_USE_INT64_N 4
#else
#define DCO_TAPE_USE_INT64_N 0
#endif
#ifdef DCO_CPP11
#define DCO_CPP11_N 8
#else
#define DCO_CPP11_N 0
#endif
#ifdef DCO_AUTO_SUPPORT
#define DCO_AUTO_SUPPORT_N 16
#else
#define DCO_AUTO_SUPPORT_N 0
#endif

#define DCO_COMPATIBILITY_VERSION                                                                                      \
  (DCO_COMPATIBILITY_VERSION_BASE + DCO_CHUNK_TAPE_N + DCO_TAPE_USE_LONG_INT_N + DCO_TAPE_USE_INT64_N + DCO_CPP11_N +  \
   DCO_AUTO_SUPPORT_N)

namespace dco {
template <int> struct build_info_t {
  static const std::string VERSION, VERSION_SHORT, BRANCH;
  static const int VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_ALPHA;
  static const int COMPATIBILITY_VERSION;
};
template <int T> const std::string build_info_t<T>::VERSION = "3.8.1";
template <int T> const std::string build_info_t<T>::VERSION_SHORT = "3.8";
template <int T> const std::string build_info_t<T>::BRANCH = "";
template <int T> const int build_info_t<T>::VERSION_MAJOR = 3;
template <int T> const int build_info_t<T>::VERSION_MINOR = 8;
template <int T> const int build_info_t<T>::VERSION_PATCH = 1;
template <int T> const int build_info_t<T>::VERSION_ALPHA = 0;
template <int T> const int build_info_t<T>::COMPATIBILITY_VERSION = T;
typedef build_info_t<DCO_COMPATIBILITY_VERSION> build_info;

static inline void print_compatibility_version(int version) {
  std::cout << "full compatibility version string = " << DCO_COMPATIBILITY_VERSION << std::endl;
  int version_base = version / 1000;

  if (version_base < 319 || version_base > 999) {
    std::cout << "version completely off; presumably a version from before compatibility was redesigned." << std::endl;
    return;
  }

  std::bitset<9> version_bits = static_cast<long long unsigned>(version - version_base * 1000);

  std::cout << "\ndco/c++ (v" << version_base / 100 << "." << (version_base % 100) / 10 << "." << version_base % 10
            << ") compile-time configuration:" << std::endl;
  std::cout << "  DCO_[CHUNK|FILE]_TAPE: " << version_bits[0] << std::endl;
  std::cout << "  DCO_TAPE_USE_LONG_INT: " << version_bits[1] << std::endl;
  std::cout << "  DCO_TAPE_USE_INT64:    " << version_bits[2] << std::endl;
  std::cout << "  DCO_CPP11            : " << version_bits[3] << std::endl;
  std::cout << "  DCO_AUTO_SUPPORT     : " << version_bits[4] << std::endl;
}

static inline void cout_diffs_in_version(int lib_version, int tape_version) {
  int tape_version_base = tape_version / 1000;
  int lib_version_base = lib_version / 1000;

  std::bitset<9> lib_version_bits = static_cast<long long unsigned>(lib_version - lib_version_base * 1000);
  std::bitset<9> tape_version_bits = static_cast<long long unsigned>(tape_version - tape_version_base * 1000);

  if (abs(tape_version - lib_version) >= 1000) {
    if (tape_version_base < 319 || tape_version_base > 999) {
      std::cout << "Tape version completely off; presumably a version from before compatibility was redesigned."
                << std::endl;
    }
    std::cout << "Using two different versions of dco/c++: " << tape_version_base << " vs. " << lib_version_base
              << std::endl;
    return;
  }

  std::cout << "dco/c++ compile-time configuration:" << std::endl;
  std::cout << std::endl;
  std::cout << " tape version (v" << tape_version_base / 100 << "." << (tape_version_base % 100) / 10 << "."
            << tape_version_base % 10 << ")_      _library version (v" << lib_version_base / 100 << "."
            << (lib_version_base % 100) / 10 << "." << lib_version_base % 10 << ")" << std::endl;
  std::cout << "                       |    |" << std::endl;
  std::cout << "                       V    V" << std::endl;
  std::cout << "DCO_[CHUNK|FILE]_TAPE: " << tape_version_bits[0] << " vs " << lib_version_bits[0] << std::endl;
  std::cout << "DCO_TAPE_USE_LONG_INT: " << tape_version_bits[1] << " vs " << lib_version_bits[1] << std::endl;
  std::cout << "DCO_TAPE_USE_INT64:    " << tape_version_bits[2] << " vs " << lib_version_bits[2] << std::endl;
  std::cout << "DCO_CPP11            : " << tape_version_bits[3] << " vs " << lib_version_bits[3] << std::endl;
  std::cout << "DCO_AUTO_SUPPORT     : " << tape_version_bits[4] << " vs " << lib_version_bits[4] << std::endl;
}

inline bool is_compatible(int version1, int version2, bool print = false) {
  if (print)
    dco::cout_diffs_in_version(version1, version2);
  return version1 == version2;
}

} // namespace dco
