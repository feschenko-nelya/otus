cmake_minimum_required(VERSION 3.14)

project(Utils VERSION 1.1)

configure_file(version.h.in version.h)

add_library(Utils STATIC utils.cpp utils.h)

#set_target_properties(Utils PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

target_include_directories(Utils PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
