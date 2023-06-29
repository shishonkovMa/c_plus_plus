cmake_minimum_required(VERSION 3.5)

project(createMapFromVec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(createMapFromVec main.cpp)

install(TARGETS createMapFromVec
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
