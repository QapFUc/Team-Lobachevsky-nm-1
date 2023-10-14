set(TARGET_NAME nm_gui)

file(GLOB_RECURSE SOURCES "*.cc" "*.h")

add_executable(${TARGET_NAME} ${SOURCES})

target_link_libraries(${TARGET_NAME} PRIVATE
    Qt6::Core 
    Qt6::Widgets
    nm::core
)

target_include_directories(${TARGET_NAME} PRIVATE include)


