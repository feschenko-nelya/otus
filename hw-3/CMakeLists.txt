cmake_minimum_required(VERSION 3.5)

project(bulk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bulk main.cpp
                    BaseBlocksReader.h BaseBlocksReader.cpp
                    FixedBlocksReader.h FixedBlocksReader.cpp
                    DynamicBlocksReader.h DynamicBlocksReader.cpp
                    BlocksReaderMgr.h BlocksReaderMgr.cpp
              )

install(TARGETS bulk
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

target_link_libraries(${PROJECT_NAME} stdc++fs)
