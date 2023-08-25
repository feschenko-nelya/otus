cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
project(bulk VERSION 0.0.${PATCH_VERSION} LANGUAGES CXX)

project(bulk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bulk main.cpp
                    BaseBlocksReader.h BaseBlocksReader.cpp
                    FixedBlocksReader.h FixedBlocksReader.cpp
                    DynamicBlocksReader.h DynamicBlocksReader.cpp
                    BlocksReaderMgr.h BlocksReaderMgr.cpp
                    IObserver.h IObserver.cpp
              )

install(TARGETS bulk
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(TARGETS bulk RUNTIME DESTINATION bin)

target_link_libraries(${PROJECT_NAME} stdc++fs)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT feschenko_n_s@list.ru)
include(CPack)
