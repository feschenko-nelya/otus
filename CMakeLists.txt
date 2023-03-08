cmake_minimum_required(VERSION 3.14)

project(Test VERSION 1 DESCRIPTION "First course project")

# enable_language(CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Test main.cpp)

target_include_directories(Test PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(utils)

target_link_libraries(Test Utils)