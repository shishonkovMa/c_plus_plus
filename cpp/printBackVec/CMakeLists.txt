cmake_minimum_required(VERSION 3.5)

project(printBackVec LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(printBackVec main.cpp)

install(TARGETS printBackVec
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
