cmake_minimum_required(VERSION 3.15)

# Quick return if NAG::dco_cpp is already imported.
if(TARGET NAG::dco_cpp)
  return()
endif()

## Tries to retrieve installation path from given product code
function(_dco_get_installation_path prodcode installation_path)
  if(WIN32)
    set(_dco_appid "\\{8B8241FE-4770-49CB-B334-1E6${prodcode}\\}_is1")
    string(CONCAT _dco_reg_path
      "HKLM\\SOFTWARE\\WOW6432Node\\Microsoft\\"
      "Windows\\CurrentVersion\\Uninstall")
    execute_process(COMMAND "reg" "query" "${_dco_reg_path}\\${_dco_appid}"
      OUTPUT_VARIABLE _installation_path_loc ERROR_QUIET)
    if(_installation_path_loc)
      string(REGEX MATCH
        "InstallLocation[ ]*REG_SZ[ ]*([^\n]*)"
        _installation_path_loc ${_installation_path_loc})
      string(REGEX REPLACE
        "InstallLocation[ ]*REG_SZ[ ]*" ""
        _installation_path_loc ${_installation_path_loc})
    endif()
    set(${installation_path} ${_installation_path_loc} PARENT_SCOPE)
  else()
    # Search default installation directories
    set(_dco_def_dirs
      $ENV{HOME}/NAG/${prodcode} /opt/NAG/${prodcode} /opt/${prodcode})
    find_file(_installation_path_loc dco.hpp
      PATHS ${_dco_def_dirs} NO_DEFAULT_PATH PATH_SUFFIXES include)
    if(_installation_path_loc)
      get_filename_component(_installation_path_loc
        ${_installation_path_loc} DIRECTORY)
      string(REPLACE
        "/include" "" _installation_path_loc ${_installation_path_loc})
    endif()
    set(${installation_path} ${_installation_path_loc} PARENT_SCOPE)
  endif()
  unset(_installation_path_loc CACHE)
ENDFUNCTION()

if("${CMAKE_SIZEOF_VOID_P}" STREQUAL "4")
  set(_dco_is_32)
  unset(_dco_is_64)
else()
  unset(_dco_is_32)
  set(_dco_is_64)
endif()

if(NOT DEFINED NAG_dco_cpp_USE_DYNAMIC_RUNTIME)
  set(NAG_dco_cpp_USE_DYNAMIC_RUNTIME FALSE)
endif()

# Local search
################################################################################
if(NOT(NAG_dco_cpp_DIR))
  find_path(NAG_dco_cpp_INCLUDE_DIR dco.hpp HINTS
    ${CMAKE_SOURCE_DIR}/dco_cpp_dev
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/..
    $ENV{HOME}/dco_cpp_dev
    $ENV{HOME}/dco
    $ENV{HOME}/dco/dco_cpp_dev
    $ENV{HOME}/git/dco_cpp_dev
    $ENV{HOME}/mygit/dco_cpp_dev
    $ENV{HOME}/Software/dco_cpp_dev
    PATH_SUFFIXES src include)

  # Set path if include dir was found otherwise try to find dco/c++ in other
  # common places (store result in NAG_dco_cpp_DIR)
  if(NAG_dco_cpp_INCLUDE_DIR)
    set(NAG_dco_cpp_DIR ${NAG_dco_cpp_INCLUDE_DIR}/..)
    get_filename_component(NAG_dco_cpp_DIR "${NAG_dco_cpp_DIR}" ABSOLUTE)
  else()
    if(WIN32)
      if(CMAKE_C_COMPILER_VERSION MATCHES "19.(.*)")
	      set(VS_NEWER_THAN_15 1)
      else()
	      set(VS_NEWER_THAN_15 0)
      endif()

      foreach(_dco_version_major 9 8 7 6 5 4 3 2)
        if(NAG_dco_cpp_DIR)
          break()
        endif()
        foreach(_dco_version_minor 9 8 7 6 5 4 3 2 1 0)
          # Try to find non-license-managed version
          _dco_get_installation_path(
            "dcwin${_dco_version_major}${_dco_version_minor}nn" NAG_dco_cpp_DIR)
          if(NAG_dco_cpp_DIR)
            break()
          endif()

          # Try to find license-managed version 64-bit pre 2015
          _dco_get_installation_path(
            "dcw6i${_dco_version_major}${_dco_version_minor}na" NAG_dco_cpp_DIR)
          if(NAG_dco_cpp_DIR AND VS_NEWER_THAN_15)
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: VS pre 2015 version found here: "
                "'${NAG_dco_cpp_DIR}'. This is not matching your currently "
                "loaded environment. Continue searching.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND _dco_is_32)
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: 64-bit version found here: "
                "'${NAG_dco_cpp_DIR}'. This is not matching your currently "
                "loaded environment. Continue searching.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND NOT(VS_NEWER_THAN_15) AND _dco_is_64)
            break()
          endif()

          # Try to find license-managed version 64-bit post 2015
          _dco_get_installation_path(
            "dcw6i${_dco_version_major}${_dco_version_minor}ne" NAG_dco_cpp_DIR)
          if(NAG_dco_cpp_DIR AND NOT(VS_NEWER_THAN_15))
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: VS post 2015 version found here: "
                "'${NAG_dco_cpp_DIR}'. This is not matching your currently "
                "loaded environment. Continue searching.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND _dco_is_32)
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: 64-bit version found here: "
                "'${NAG_dco_cpp_DIR}'. This is not matching your currently "
                "loaded environment. Continue searching.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND VS_NEWER_THAN_15 AND _dco_is_64)
            break()
          endif()

          # Try to find license-managed version 32-bit pre 2015
          _dco_get_installation_path(
            "dcw32${_dco_version_major}${_dco_version_minor}na" NAG_dco_cpp_DIR)
          if(NAG_dco_cpp_DIR AND VS_NEWER_THAN_15)
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: VS pre 2015 version found here: "
                "'${NAG_dco_cpp_DIR}'. This is not matching your currently "
                "loaded environment. Continue searching.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND _dco_is_64)
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: 32-bit version found here: "
                "'${NAG_dco_cpp_DIR}'. This is not matching your currently "
                "loaded environment. Continue searching.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND NOT(VS_NEWER_THAN_15) AND _dco_is_64)
            break()
          endif()

          # Try to find license-managed version 32-bit post 2015
          _dco_get_installation_path(
            "dcw32${_dco_version_major}${_dco_version_minor}ne" NAG_dco_cpp_DIR)
          if(NAG_dco_cpp_DIR AND NOT(VS_NEWER_THAN_15))
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: VS post 2015 version found here: "
                "'${NAG_dco_cpp_DIR}'. This is not matching your currently "
                "loaded environment. Continue searching.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND _dco_is_64)
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: 32-bit version found here: "
                "'${NAG_dco_cpp_DIR}'. This is not matching your currently "
                "loaded environment. Continue searching.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND VS_NEWER_THAN_15 AND _dco_is_32)
            break()
          endif()
        endforeach()
      endforeach()
    else() # LINUX
      foreach(_dco_version_major 9 8 7 6 5 4 3 2)
        if(NAG_dco_cpp_DIR)
          break()
        endif()
        foreach(_dco_version_minor 9 8 7 6 5 4 3 2 1 0)
          # Try to find non-license-managed version
          _dco_get_installation_path(
            "dclin${_dco_version_major}${_dco_version_minor}nn"
            NAG_dco_cpp_DIR)
          if(NAG_dco_cpp_DIR)
            break()
          endif()

          # Try to find license-managed version 64-bit
          _dco_get_installation_path(
            "dcl6i${_dco_version_major}${_dco_version_minor}ngl"
            NAG_dco_cpp_DIR)
          if(NAG_dco_cpp_DIR AND _dco_is_64)
            break()
          endif()

          # Try to find license-managed version 32-bit
          _dco_get_installation_path(
            "dclux${_dco_version_major}${_dco_version_minor}ngl"
            NAG_dco_cpp_DIR)
          if(NAG_dco_cpp_DIR AND _dco_is_64)
            if(NOT(NAG_dco_cpp_FIND_QUIETLY))
              message(STATUS
                "NAG config - dco/c++: 32-bit version found here: "
                "'${NAG_dco_cpp_DIR}'. Continue searching. If you really want "
                "to use this 32-bit version on your 64-bit system, please "
                "specify NAG_dco_cpp_DIR explicitly.")
            endif()
          endif()
          if(NAG_dco_cpp_DIR AND _dco_is_32)
            break()
          endif()
        endforeach()
      endforeach()
    endif()
  endif()
else()
  if(NOT(IS_ABSOLUTE ${NAG_dco_cpp_DIR}))
    if(NOT(NAG_dco_cpp_FIND_QUIETLY))
      message(WARNING
        "NAG config - dco/c++: Relative path given as NAG_dco_cpp_DIR; "
        "interpreted as relative to CMAKE_CURRENT_SOURCE_DIR, i.e. "
        "'${CMAKE_CURRENT_SOURCE_DIR}/${NAG_dco_cpp_DIR}'.")
    endif()
  endif()
endif()

# From here on, NAG_dco_cpp_DIR should be defined
#################################################
get_filename_component(NAG_dco_cpp_DIR "${NAG_dco_cpp_DIR}" ABSOLUTE)

# Find path to dco.hpp
find_path(NAG_dco_cpp_INCLUDE_DIR dco.hpp HINTS
  ${NAG_dco_cpp_DIR}/include
  ${NAG_dco_cpp_DIR}/src
  ${NAG_dco_cpp_DIR})

if(NOT(NAG_dco_cpp_INCLUDE_DIR))
  if(NAG_dco_cpp_FIND_REQUIRED)
    message(FATAL_ERROR
      "NAG config - dco/c++: not found. Set NAG_dco_cpp_DIR respectively.")
  else()
    if(NOT(NAG_dco_cpp_FIND_QUIETLY))
    message(WARNING
      "NAG config - dco/c++: not found. Set NAG_dco_cpp_DIR respectively.")
    endif()
  endif()
  unset(NAG_dco_cpp_INCLUDE_DIR CACHE)
  return()
endif()

file(READ ${NAG_dco_cpp_INCLUDE_DIR}/dco.hpp FILE_CONTENTS)
string(REGEX REPLACE
  ".*used DCO_FLAGS: \(.*\)" "\\1" _DCO_HPP_BUILD_DEFINES ${FILE_CONTENTS})
if(_DCO_HPP_BUILD_DEFINES MATCHES "DCO_LICENSE")
  set(_DCO_LICENSE YES)
endif()

set(NAG_dco_cpp_INCLUDE_DIRS ${NAG_dco_cpp_INCLUDE_DIR})
mark_as_advanced(NAG_dco_cpp_INCLUDE_DIR)
mark_as_advanced(NAG_dco_cpp_INCLUDE_DIRS)

# Get dco/c++ version number
############################
set(DCO_VERSION_MAJOR "0")
set(DCO_VERSION_MINOR "0")
set(DCO_VERSION_PATCH "0")
find_file(_DCO_VERSION_HPP dco_version.hpp HINTS
  ${NAG_dco_cpp_DIR}/include
  ${NAG_dco_cpp_DIR}/src
  ${NAG_dco_cpp_DIR})
if(_DCO_VERSION_HPP)
  file(READ ${_DCO_VERSION_HPP} FILE_CONTENTS)
  string(REGEX REPLACE
    ".*#define DCO_VERSION [v]*\([0-9].[0-9].[0-9]\).*" "\\1"
    VERSION ${FILE_CONTENTS})
  string(REGEX REPLACE
    "\([0-9]\).[0-9].[0-9]" "\\1" DCO_VERSION_MAJOR ${VERSION})
  string(REGEX REPLACE
    "[0-9].\([0-9]\).[0-9]" "\\1" DCO_VERSION_MINOR ${VERSION})
  string(REGEX REPLACE
    "[0-9].[0-9].\([0-9]\)" "\\1" DCO_VERSION_PATCH ${VERSION})
endif()
unset(_DCO_VERSION_HPP CACHE)

# Licensed version? => search library
#####################################
if(WIN32)
  set(_dco_library_name libdcoc)
  find_library(
    NAG_dco_cpp_LIBRARY_MD NAMES ${_dco_library_name}_MD
    HINTS ${NAG_dco_cpp_DIR}/lib)
  find_library(NAG_dco_cpp_LIBRARY_MT NAMES ${_dco_library_name}_MT
    HINTS ${NAG_dco_cpp_DIR}/lib)
  find_library(NAG_dco_cpp_LIBRARY_MDd NAMES ${_dco_library_name}_MDd
    HINTS ${NAG_dco_cpp_DIR}/lib)
  find_library(NAG_dco_cpp_LIBRARY_MTd NAMES ${_dco_library_name}_MTd
    HINTS ${NAG_dco_cpp_DIR}/lib)
  set(NAG_dco_cpp_LIBRARY ${NAG_dco_cpp_LIBRARY_MD})
else()
  find_library(NAG_dco_cpp_LIBRARY NAMES dcoc HINTS ${NAG_dco_cpp_DIR}/lib)
endif()
get_filename_component(_dco_library_dir ${NAG_dco_cpp_LIBRARY} DIRECTORY)

# Finalize find_package with some output
########################################
string(CONCAT _dco_cpp_version
  "${DCO_VERSION_MAJOR}."
  "${DCO_VERSION_MINOR}."
  "${DCO_VERSION_PATCH}")
string(CONCAT _dco_cpp_find_version
  "${NAG_dco_cpp_FIND_VERSION_MAJOR}."
  "${NAG_dco_cpp_FIND_VERSION_MINOR}."
  "${NAG_dco_cpp_FIND_VERSION_PATCH}")

if(${_dco_cpp_version} VERSION_LESS ${_dco_cpp_find_version})
  message(FATAL_ERROR
    "NAG config - dco/c++: not found. Required version "
    "${_dco_cpp_find_version} larger than detected version "
    "${_dco_cpp_version}. Set NAG_dco_cpp_DIR respectively.")
endif()

if(NAG_dco_cpp_FIND_VERSION_EXACT)
  if(NOT ${_dco_cpp_version} VERSION_EQUAL ${_dco_cpp_find_version})
    message(FATAL_ERROR
      "NAG config - dco/c++: not found. Required version "
      "${_dco_cpp_find_version} doesn't match detected version "
      "${_dco_cpp_version}. Set NAG_dco_cpp_DIR respectively.")
  endif()
endif()

if(NOT(NAG_dco_cpp_INCLUDE_DIR) OR (_DCO_LICENSE AND NOT(NAG_dco_cpp_LIBRARY)))
  set(NAG_dco_cpp_FOUND 0)
  if(NAG_dco_cpp_FIND_REQUIRED)
    if(NOT(NAG_dco_cpp_INCLUDE_DIR))
      message(FATAL_ERROR
        "NAG config - dco/c++: include directory not found. "
        "Set NAG_dco_cpp_DIR respectively.")
    else()
      message(FATAL_ERROR
        "NAG config - dco/c++: library not found. "
        "Check correct installation.")
    endif()
  else()
    if(NOT(NAG_dco_cpp_FIND_QUIETLY))
      if(NOT(NAG_dco_cpp_INCLUDE_DIR))
        message(WARNING
          "NAG config - dco/c++: include directory not found. "
          "Set NAG_dco_cpp_DIR respectively.")
      else()
	      message(WARNING
          "NAG config - dco/c++: library not found. "
          "Check correct installation.")
      endif()
    endif()
  endif()
else()
  if(NAG_dco_cpp_DIR)
    if(NOT(NAG_dco_cpp_FIND_QUIETLY))
      message(STATUS
        "NAG config - dco/c++: Picking v${_dco_cpp_version} in "
        "'${NAG_dco_cpp_DIR}'. Imported target 'NAG::dco_cpp'.")
    endif()
  endif()
  mark_as_advanced(DCO_VERSION_MAJOR)
  mark_as_advanced(DCO_VERSION_MINOR)
  mark_as_advanced(DCO_VERSION_PATCH)
  set(NAG_dco_cpp_FOUND 1)

  if(NAG_dco_cpp_LIBRARY)
    if(WIN32)
      set(_dco_cpp_compile_options
        "/NODEFAULTLIB:MSVCRT$<$<NOT:$<CONFIG:Debug>>:D>"
        "/NODEFAULTLIB:LIBCMT$<$<NOT:$<CONFIG:Debug>>:D>")

      add_library(NAG::dco_cpp_MT STATIC IMPORTED)
      set_target_properties(NAG::dco_cpp_MT
        PROPERTIES IMPORTED_LOCATION "${NAG_dco_cpp_LIBRARY_MT}")
      set_target_properties(NAG::dco_cpp_MT
        PROPERTIES INTERFACE_LINK_OPTIONS  "${_dco_cpp_compile_options}")
      add_library(NAG::dco_cpp_MTd STATIC IMPORTED)
      set_target_properties(NAG::dco_cpp_MTd
        PROPERTIES IMPORTED_LOCATION "${NAG_dco_cpp_LIBRARY_MTd}")
      set_target_properties(NAG::dco_cpp_MTd
        PROPERTIES INTERFACE_LINK_OPTIONS  "${_dco_cpp_compile_options}")
      add_library(NAG::dco_cpp_MD STATIC IMPORTED)
      set_target_properties(NAG::dco_cpp_MD
        PROPERTIES IMPORTED_LOCATION "${NAG_dco_cpp_LIBRARY_MD}")
      set_target_properties(NAG::dco_cpp_MD
        PROPERTIES INTERFACE_LINK_OPTIONS  "${_dco_cpp_compile_options}")
      add_library(NAG::dco_cpp_MDd STATIC IMPORTED)
      set_target_properties(NAG::dco_cpp_MDd
        PROPERTIES IMPORTED_LOCATION "${NAG_dco_cpp_LIBRARY_MDd}")
      set_target_properties(NAG::dco_cpp_MDd
        PROPERTIES INTERFACE_LINK_OPTIONS  "${_dco_cpp_compile_options}")

      add_library(NAG::dco_cpp INTERFACE IMPORTED GLOBAL)
      if((CMAKE_MSVC_RUNTIME_LIBRARY MATCHES "DLL") OR (NAG_USE_DYNAMIC_RUNTIME))
	      set_target_properties(NAG::dco_cpp
          PROPERTIES INTERFACE_LINK_LIBRARIES
          "NAG::dco_cpp_MD$<$<CONFIG:Debug>:d>")
      else()
	      set_target_properties(NAG::dco_cpp
          PROPERTIES INTERFACE_LINK_LIBRARIES
          "NAG::dco_cpp_MT$<$<CONFIG:Debug>:d>")
      endif()
      set_property(
	TARGET NAG::dco_cpp
	APPEND PROPERTY
        INTERFACE_LINK_LIBRARIES "user32" "advapi32" "ws2_32"
	)
      set_target_properties(NAG::dco_cpp
        PROPERTIES INTERFACE_LINK_DIRECTORIES "${_dco_library_dir}")
    else()
      add_library(NAG::dco_cpp STATIC IMPORTED GLOBAL)
      set_target_properties(NAG::dco_cpp
        PROPERTIES IMPORTED_LOCATION "${NAG_dco_cpp_LIBRARY}")
    endif()
  else()
    add_library(NAG::dco_cpp INTERFACE IMPORTED GLOBAL)
  endif()
  set_target_properties(NAG::dco_cpp
    PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${NAG_dco_cpp_INCLUDE_DIR}")
endif()

unset(NAG_dco_cpp_INCLUDE_DIR CACHE)
unset(NAG_dco_cpp_LIBRARY CACHE)
if(WIN32)
  unset(NAG_dco_cpp_LIBRARY_MD CACHE)
  unset(NAG_dco_cpp_LIBRARY_MT CACHE)
  unset(NAG_dco_cpp_LIBRARY_MDd CACHE)
  unset(NAG_dco_cpp_LIBRARY_MTd CACHE)
endif()
