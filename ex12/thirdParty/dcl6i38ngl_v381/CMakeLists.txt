cmake_minimum_required (VERSION 3.15)
cmake_policy(VERSION 3.15)

# Set a default build type if none was specified.
set(default_build_type "RelWithDebInfo")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

project(dco_cpp
  LANGUAGES CXX
  VERSION 3.8.1
  DESCRIPTION "NAG dco/c++ package."
  HOMEPAGE_URL "https://www.nag.com/content/algorithmic-differentiation-software")

## C++11 required for dco/c++.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
  option(BUILD_USE_DYNAMIC_RUNTIME "Enable MD build." ON)
  if (BUILD_USE_DYNAMIC_RUNTIME)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
  else()
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  endif()
  ## Disable Warning 4503: decorated name length exceeded.
  add_compile_options(/wd4503)
endif()

## Helper macro used below: get all directories in dir.
macro(dco_get_subdirs dir result)
  file(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/${dir} ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(OpenMP)
find_package(NAG_dco_cpp REQUIRED)
## Switching to chunk tape use. The chunk tape is less efficient than
## blob tape in general (on release builds); but since Windows
## initializes memory on allocation for Debug builds, the chunk tape
## is chosen by default here (to minimize the time required for
## that). Please switch to blob tape for any type of benchmarking.
add_definitions(-DDCO_CHUNK_TAPE)

enable_testing()
add_executable(run_prog_and_diff cmake/run_prog_and_diff.cpp)

add_subdirectory(examples)
add_subdirectory(case_studies)
