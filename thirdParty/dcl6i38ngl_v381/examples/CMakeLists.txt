dco_get_subdirs(. dirs)
add_custom_target(examples)
foreach(dir ${dirs})
  file(GLOB files ${dir}/*.cpp)
  add_executable(examples.${dir} ${files})
  target_link_libraries(examples.${dir} PRIVATE OpenMP::OpenMP_CXX NAG::dco_cpp)
  target_compile_definitions(examples.${dir}
    PRIVATE DCO_DISABLE_AUTO_WARNING DCO_DISABLE_AVX2_WARNING)

  set(outputfile "examples.${dir}.r")
  set(resultfile "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/ref_results")
  add_test(
    NAME examples.${dir}
    COMMAND "$<TARGET_FILE:run_prog_and_diff>" "$<TARGET_FILE:examples.${dir}>" "${outputfile}" "${resultfile}" "0"
    )

  add_dependencies(examples.${dir} run_prog_and_diff)
  add_dependencies(examples examples.${dir})
endforeach()


