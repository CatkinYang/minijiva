add_subdirectory(accessflag)
add_subdirectory(constant)
add_subdirectory(attribute)

file(GLOB_RECURSE MINIJAVA_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(minijava STATIC ${MINIJAVA_SOURCES} ${ALL_OBJECT_FILES})

set(MINI_LIBS accessflag constant attribute)

target_link_libraries(minijava ${MINI_LIBS} ${MINI_THIRDPARTY_LIBS})

target_include_directories(
  minijava PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
