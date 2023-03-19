cmake_minimum_required(VERSION 3.14)

project(ShowVersion VERSION 1 DESCRIPTION "First course project")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ShowVersion main.cpp)

target_include_directories(ShowVersion PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(utils)

target_link_libraries(ShowVersion Utils)