cmake_minimum_required(VERSION 3.21)

project(nm_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_INIT "-Wall")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(ENABLE_QT6)
    find_package(Qt6 REQUIRED COMPONENTS Core Widgets PATHS ${QT6_LIB_PATH})
endif()

# include_directories("${QT6_LIB_PATH}/include")

add_subdirectory(src)


