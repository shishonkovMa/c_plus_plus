cmake_minimum_required(VERSION 3.5)

project(common_prefix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(common_prefix main.cpp)

install(TARGETS common_prefix
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
