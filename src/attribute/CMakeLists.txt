file(GLOB SOURCES "*.cpp")

add_library(attribute STATIC ${SOURCES})

set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:attribute>
    PARENT_SCOPE)
