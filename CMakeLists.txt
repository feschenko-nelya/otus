cmake_minimum_required(VERSION 3.14)

project(helloworld VERSION 1 DESCRIPTION "First course project")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(helloworld_cli main.cpp)

target_include_directories(helloworld_cli PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(utils)

target_link_libraries(helloworld_cli Utils)