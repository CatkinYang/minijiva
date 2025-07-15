file(GLOB SOURCES "*.cpp")

add_library(constant OBJECT ${SOURCES})

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:constant>
    PARENT_SCOPE)
