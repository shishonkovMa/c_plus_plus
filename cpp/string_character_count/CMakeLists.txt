cmake_minimum_required(VERSION 3.5)

project(string_character_count LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(string_character_count main.cpp)

install(TARGETS string_character_count
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
