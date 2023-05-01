cmake_minimum_required(VERSION 3.14)

project("GTests")

enable_testing()
add_subdirectory(googletest)
add_executable(gtest_version main.cpp ../../../utils/utils.h ../../../utils/utils.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(gtest_version gtest_main gmock_main)
add_test(NAME TestGroup COMMAND gtest_version)