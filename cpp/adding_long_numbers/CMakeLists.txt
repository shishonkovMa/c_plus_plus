cmake_minimum_required(VERSION 3.5)

project(adding_long_numbers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(adding_long_numbers main.cpp)

install(TARGETS adding_long_numbers
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
