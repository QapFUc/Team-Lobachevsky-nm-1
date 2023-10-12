set(TARGET_NAME nm_core_lib)

file(GLOB_RECURSE SOURCES "*.cc" "*.hpp")

add_library(${TARGET_NAME} STATIC ${SOURCES})
add_library(nm::core ALIAS ${TARGET_NAME})