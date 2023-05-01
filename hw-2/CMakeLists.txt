cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
project(ip_filter VERSION 0.0.${PATCH_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ip_filter main.cpp)

target_include_directories(ip_filter PUBLIC ${PROJECT_BINARY_DIR})
add_subdirectory(utils)
target_link_libraries(ip_filter Utils)

install(TARGETS ip_filter
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT feschenko_n_s@list.ru)
include(CPack)
