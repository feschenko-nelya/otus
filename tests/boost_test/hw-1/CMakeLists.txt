cmake_minimum_required(VERSION 3.14)

project(Tests VERSION 1.1)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.7z
    DOWNLOAD_EXTRACT_TIMESTAMP ON
)
FetchContent_MakeAvailable(Boost)

set(Boost_NO_WARN_NEW_VERSIONS ON)

set(BOOST_ENABLE_CMAKE ON)
set(BOOST_INCLUDE_LIBRARIES test)

add_executable(Tests test_version.cpp ../../../hw-1/utils/utils.cpp ../../../hw-1/utils/utils.h)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(Tests Boost::unit_test_framework)

add_test(NAME test_version COMMAND Tests)
