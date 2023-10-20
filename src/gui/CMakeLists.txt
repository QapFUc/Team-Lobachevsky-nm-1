set(TARGET_NAME nm_gui)

file(GLOB_RECURSE SOURCES "*.cc" "*.h")

add_executable(${TARGET_NAME} ${SOURCES}
    src/mainwindow.ui src/tablewindow.ui)

target_link_libraries(${TARGET_NAME} PRIVATE
    Qt6::Core 
    Qt6::PrintSupport
    Qt6::Widgets
    nm::core
    qcustomplot
)

set_target_properties(${TARGET_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(${TARGET_NAME} PRIVATE include)



