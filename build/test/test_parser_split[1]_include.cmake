if(EXISTS "/Users/catkin/workspace/hygon/minijiva/build/test/test_parser_split[1]_tests.cmake")
  include("/Users/catkin/workspace/hygon/minijiva/build/test/test_parser_split[1]_tests.cmake")
else()
  add_test(test_parser_split_NOT_BUILT test_parser_split_NOT_BUILT)
endif()
