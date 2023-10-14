cmake_minimum_required(VERSION 3.21)

project(nm_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_INIT "-Wall")


add_subdirectory(src)
add_executable(nm_lab main.cc)



if(ENABLE_QT6)
    find_package(Qt6 REQUIRED COMPONENTS Core PATHS ${QT6_LIB_PATH})
    qt_standart_project_setup()

    qt_add_executable(nm_lab main.cpp)
    

    target_link_libraries(nm_lab PRIVATE Qt6::Core)
endif()

if(ENABLE_QT5)
    find_package(Qt5 REQUIRED COMPONENTS Core PATHS ${QT6_LIB_PATH})
    qt_standart_project_setup()

    qt_add_executable(nm_lab main.cpp)

    target_link_libraries(nm_lab PRIVATE Qt5::Core)
endif()

target_link_libraries(nm_lab PRIVATE
    nm::core 
)



