cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ##############################################################################
set(PROJECT_NAME "minijava")
project(${PROJECT_NAME})
message(STATUS "PROJECT_NAME: " ${PROJECT_NAME})

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to `Debug` as none was specified.")
  set(CMAKE_BUILD_TYPE "Debug")
endif()

# ##############################################################################

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt"
     PATH_TO_CMAKELISTS_TXT)

if(EXISTS "${PATH_TO_CMAKELISTS_TXT}")
  message(
    FATAL_ERROR
      "Run CMake from a build subdirectory! \"mkdir build ; cd build ; cmake ..\" \
    Some junk files were created in this folder (CMakeCache.txt, CMakeFiles); you should delete those."
  )
endif()

# ##############################################################################

set(PRJ_BUILD_SUPPORT_DIR "${CMAKE_SOURCE_DIR}/build_support")
set(PRJ_CLANG_SEARCH_PATH "/usr/local/bin" "/usr/bin")

# ##############################################################################
# CTest
enable_testing()

# ##############################################################################
# COMPILER SETUP
# ##############################################################################
if(NOT DEFINED PRJ_SANITIZER)
  set(PRJ_SANITIZER address)
endif()

message("Build mode: ${CMAKE_BUILD_TYPE}")
message("${PRJ_SANITIZER} sanitizer will be enabled in debug mode.")

# Compiler flags.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -Wno-unused-parameter -Wno-attributes") # TODO:
                                                                      # remove
set(CMAKE_CXX_FLAGS_DEBUG
    "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -fsanitize=${PRJ_SANITIZER} -fno-omit-frame-pointer -fno-optimize-sibling-calls"
)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_EXE_LINKER_FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")
message(STATUS "CMAKE_SHARED_LINKER_FLAGS: ${CMAKE_SHARED_LINKER_FLAGS}")

# Output directory.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Includes.
set(PRJ_SRC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/src/include)
set(PRJ_TEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/test/include)
set(PRJ_THIRD_PARTY_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/third_party)

include_directories(${PRJ_SRC_INCLUDE_DIR} ${PRJ_TEST_INCLUDE_DIR}
                    ${PRJ_THIRD_PARTY_INCLUDE_DIR})
include_directories(BEFORE src) # This is needed for gtest.

add_subdirectory(third_party)
add_subdirectory(src)
add_subdirectory(test)
