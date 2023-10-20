set(TARGET_NAME qcustomplot)

file(GLOB_RECURSE SOURCES "*.h" "*.cpp")

add_library(${TARGET_NAME} SHARED ${SOURCES})
target_link_libraries(${TARGET_NAME} PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::PrintSupport
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)