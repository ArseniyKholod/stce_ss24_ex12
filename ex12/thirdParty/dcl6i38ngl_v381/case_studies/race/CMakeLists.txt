dco_get_subdirs(. dirs)
set(prefix case_studies.race)
add_custom_target(${prefix})
add_dependencies(case_studies ${prefix})

foreach(dir ${dirs})
  if (NOT(${dir} MATCHES "include"))
    add_executable(${prefix}.${dir} ${dir}/main.cpp)
    target_link_libraries(${prefix}.${dir} PRIVATE OpenMP::OpenMP_CXX NAG::dco_cpp)
    target_compile_definitions(${prefix}.${dir}
      PRIVATE DCO_DISABLE_AUTO_WARNING DCO_DISABLE_AVX2_WARNING)

    set(outputfile "${prefix}.${dir}.r")
    set(resultfile "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/ref_results")

    if (${dir} MATCHES "gt1v")
      set(PARAMETERS "100")
    else()
      set(PARAMETERS "5")
    endif()

    set_target_properties(${prefix}.${dir} PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "${PARAMETERS}")
    add_test(
      NAME ${prefix}.${dir}
      COMMAND "$<TARGET_FILE:run_prog_and_diff>" "$<TARGET_FILE:${prefix}.${dir}>" "${outputfile}" "${resultfile}" "0" "${PARAMETERS}"
      )

    add_dependencies(${prefix}.${dir} run_prog_and_diff)
    add_dependencies(${prefix} ${prefix}.${dir})
  endif()
endforeach()
