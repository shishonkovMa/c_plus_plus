cmake_minimum_required(VERSION 3.5)

project(printMap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(printMap main.cpp)

install(TARGETS printMap
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
