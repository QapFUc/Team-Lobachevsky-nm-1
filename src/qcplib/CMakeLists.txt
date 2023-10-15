set(TARGET_NAME qcustomplot)

file(GLOB_RECURSE SOURCES "*.h" "*.cpp")

add_library(${TARGET_NAME} SHARED ${SOURCES})
target_link_libraries(${TARGET_NAME} PRIVATE 
    Qt6::Core
    Qt6::Gui
)

target_include_directories(${TARGET_NAME} PRIVATE include)