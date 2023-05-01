cmake_minimum_required(VERSION 3.5)

project(Utils LANGUAGES CXX)

add_library(Utils STATIC IpAddress.h IpAddress.cpp IpAddresses.h IpAddresses.cpp)
target_include_directories(Utils PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
