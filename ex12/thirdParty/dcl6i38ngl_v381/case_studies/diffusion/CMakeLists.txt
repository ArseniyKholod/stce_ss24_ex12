dco_get_subdirs(. dirs)
set(prefix case_studies.diffusion)
add_custom_target(${prefix})
add_dependencies(case_studies ${prefix})

## copy observation data for parameter 10 50
configure_file(
  ${CMAKE_SOURCE_DIR}/case_studies/diffusion/obs/O.txt
  ${CMAKE_CURRENT_BINARY_DIR}/O.txt
  COPYONLY)


foreach(dir ${dirs})
  if (NOT(${dir} MATCHES "include"))
    add_executable(${prefix}.${dir} ${dir}/main.cpp)
    target_link_libraries(${prefix}.${dir} PRIVATE OpenMP::OpenMP_CXX NAG::dco_cpp)
    target_compile_definitions(${prefix}.${dir}
      PRIVATE DCO_DISABLE_AUTO_WARNING DCO_DISABLE_AVX2_WARNING)

    set(outputfile "${prefix}.${dir}.r")
    set(resultfile "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/ref_results")

    if (${dir} MATCHES "_cp")
      set(PARAMETERS "10 100 10")
    else()
      set(PARAMETERS "10 50")
    endif()

    ## numbers just not accurate enough
    if (${dir} MATCHES "sofd")
      set_target_properties(${prefix}.${dir} PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "10 50")
      add_test(
        NAME ${prefix}.${dir}
        COMMAND $<TARGET_FILE:${prefix}.${dir}> 10 50
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )
    else()
      set_target_properties(${prefix}.${dir} PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "${PARAMETERS}")
      add_test(
        NAME ${prefix}.${dir}
        COMMAND "$<TARGET_FILE:run_prog_and_diff>" "$<TARGET_FILE:${prefix}.${dir}>" "${outputfile}" "${resultfile}" "0" "${PARAMETERS}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )
      add_dependencies(${prefix}.${dir} run_prog_and_diff)
    endif()
    add_dependencies(${prefix} ${prefix}.${dir})
  endif()
endforeach()
