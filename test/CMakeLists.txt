cmake_minimum_required(VERSION 3.10)

include(GoogleTest)

file(GLOB_RECURSE PRJ_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/test_*.cpp")

# ##############################################################################
# MAKE TARGETS
# ##############################################################################

add_custom_target(build-tests COMMAND ${CMAKE_CTEST_COMMAND} --show-only)

# ##############################################################################
# "make XYZ_test"
# ##############################################################################
message(STATUS "PRJ_TEST_SOURCES: ${PRJ_TEST_SOURCES}")
foreach(mini_test_source ${PRJ_TEST_SOURCES})
  # Create a human readable name.
  get_filename_component(mini_test_filename ${mini_test_source} NAME)
  string(REPLACE ".cpp" "" mini_test_name ${mini_test_filename})

  # Add the test target separately and as part of "make check-tests".
  # add_executable(${mini_test_name} EXCLUDE_FROM_ALL)
  add_executable(${mini_test_name} ${mini_test_source})
  # add_backward(${mini_test_name})
  add_dependencies(build-tests ${mini_test_name})

  gtest_discover_tests(
    ${mini_test_name}
    EXTRA_ARGS --gtest_output=xml:${CMAKE_BINARY_DIR}/test/${mini_test_name}.xml
               --gtest_catch_exceptions=0 DISCOVERY_TIMEOUT 120
    PROPERTIES
    TIMEOUT 120)

  target_link_libraries(${mini_test_name} minijava gtest)

  # Set test target properties and dependencies.
  set_target_properties(
    ${mini_test_name}
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
               COMMAND ${mini_test_name})
endforeach()

# 添加一个自定义目标，用于运行所有测试 add_custom_target(check-tests)
