cmake_minimum_required(VERSION 3.5)

project(RingBuffer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RingBuffer main.cpp)

install(TARGETS RingBuffer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
