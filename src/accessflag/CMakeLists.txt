file(GLOB SOURCES "*.cpp")

add_library(accessflag OBJECT ${SOURCES})

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:accessflag>
    PARENT_SCOPE)
