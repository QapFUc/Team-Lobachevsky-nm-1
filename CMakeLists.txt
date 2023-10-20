cmake_minimum_required(VERSION 3.21)

project(nm_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_INIT "-Wall")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

option(ENABLE_QT6 "Enables qt6 package" ON)

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    add_definitions(-DDEBUG)
endif()

if(ENABLE_QT6)
    find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui PrintSupport PATHS ${QT6_LIB_PATH})
endif()

add_subdirectory(src)

add_executable(dbg_main main.cc)
target_link_libraries(dbg_main PRIVATE 
    nm::core
)


