cmake_minimum_required(VERSION 3.5)

project(findKeyInSet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(findKeyInSet main.cpp)

install(TARGETS findKeyInSet
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
