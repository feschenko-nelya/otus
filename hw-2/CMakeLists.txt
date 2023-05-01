cmake_minimum_required(VERSION 3.5)

project(ip_filter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ip_filter main.cpp)

target_include_directories(ip_filter PUBLIC ${PROJECT_BINARY_DIR})
add_subdirectory(utils)
target_link_libraries(ip_filter Utils)

install(TARGETS ip_filter
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
