/**
dco/c++ v3.8.1
    -- Algorithmic Differentiation by Operator Overloading in C++

COPYRIGHT 2022
The Numerical Algorithms Group Limited and
Software and Tools for Computational Engineering @ RWTH Aachen University

This file is part of dco/c++.
**/

#pragma once

#define DCO_EXT_EIGEN_WORLD_VERSION 3
#define DCO_EXT_EIGEN_MAJOR_VERSION 3
#define DCO_EXT_EIGEN_MINOR_VERSION 9

#if (defined EIGEN_MACROS_H) && (!defined EIGEN_DCO) && (!defined DCO_EXT_NO_EIGEN)
#if (!defined DCO_EXT_EIGEN_IGNORE_VERSION) &&                                                                         \
    (EIGEN_WORLD_VERSION != DCO_EXT_EIGEN_WORLD_VERSION || EIGEN_MAJOR_VERSION != DCO_EXT_EIGEN_MAJOR_VERSION ||       \
     EIGEN_MINOR_VERSION != DCO_EXT_EIGEN_MINOR_VERSION)
#define STRINGIFY(s) XSTRINGIFY(s)
#define XSTRINGIFY(s) #s

#pragma message(                                                                                                                                      \
    "The dco/c++ Eigen header is for Eigen version " STRINGIFY(DCO_EXT_EIGEN_WORLD_VERSION) "." STRINGIFY(DCO_EXT_EIGEN_MAJOR_VERSION) "." STRINGIFY( \
        DCO_EXT_EIGEN_MINOR_VERSION) ", but the included Eigen version is " STRINGIFY(EIGEN_WORLD_VERSION) "." STRINGIFY(EIGEN_MAJOR_VERSION) "." STRINGIFY(EIGEN_MINOR_VERSION) "! Define 'DCO_EXT_EIGEN_IGNORE_VERSION' to include the header nonetheless or 'DCO_EXT_NO_EIGEN' to suppress this message.")
#else
#if (!defined DCO_NO_INTERMEDIATES && !defined DCO_EXT_EIGEN_IGNORE_NO_INTERMEDIATES)
#ifdef _MSC_VER
#pragma message(                                                                                                       \
    "Eigen headers are found. In case you are using dco/c++ types inside Eigen, consider defining 'DCO_NO_INTERMEDIATES' in case of compilation errors. You can disable this warning by defining 'DCO_EXT_EIGEN_IGNORE_NO_INTERMEDIATES'.")
#else
#warning Eigen headers are found. In case you are using dco/c++ types inside Eigen, consider defining 'DCO_NO_INTERMEDIATES' in case of compilation errors. You can disable this warning by defining 'DCO_EXT_EIGEN_IGNORE_NO_INTERMEDIATES'.
#endif
#endif

#define DCO_STD_COMPATIBILITY

#define DCO_EXT_EIGEN
#endif
#endif
