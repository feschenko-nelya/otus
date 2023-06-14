cmake_minimum_required(VERSION 3.14)

project("GTests")

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(gtest_version main.cpp ../../../hw-1/utils/utils.h ../../../hw-1/utils/utils.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_include_directories(
        gtest_version
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)
#include_directories("../googletest/")

target_link_libraries(gtest_version gtest_main gmock_main)
add_test(NAME TestGroup COMMAND gtest_version)
