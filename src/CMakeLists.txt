

add_library(minijava STATIC ${ALL_OBJECT_FILES})

target_include_directories(
  minijava PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
             $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
