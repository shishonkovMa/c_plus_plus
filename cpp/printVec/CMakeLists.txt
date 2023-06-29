cmake_minimum_required(VERSION 3.5)

project(printVec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(printVec main.cpp)

install(TARGETS printVec
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
