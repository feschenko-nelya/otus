cmake_minimum_required(VERSION 3.14)

project(Utils VERSION 1.1)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_library(Utils STATIC utils.cpp utils.h)

target_include_directories(Utils PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
