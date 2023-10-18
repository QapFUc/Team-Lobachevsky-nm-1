cmake_minimum_required(VERSION 3.21)

project(nm_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_INIT "-Wall")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui PrintSupport PATHS ${QT6_LIB_PATH})


# include_directories("${QT6_LIB_PATH}/include")

add_subdirectory(src)

add_executable(dbg_main main.cc)
target_link_libraries(dbg_main PRIVATE 
    nm::core
)


target_include_directories(dbg_main PRIVATE src/core/include)


