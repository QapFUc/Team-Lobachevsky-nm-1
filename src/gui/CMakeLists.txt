set(TARGET_NAME nm_gui)

file(GLOB_RECURSE LIB_SOURCES "src/lib/*.cc" "*.h")
add_library(nm_gui_lib SHARED ${LIB_SOURCES})
add_library(nm::gui ALIAS nm_gui_lib)

target_link_libraries(nm_gui_lib PRIVATE
    Qt6::Core 
    Qt6::Widgets
)

target_include_directories(nm_gui_lib PRIVATE include)

add_executable(${TARGET_NAME} src/main.cc)

target_link_libraries(${TARGET_NAME} PRIVATE 
    nm::core 
    nm::gui
)


