cmake_minimum_required(VERSION 3.5)

project(polindrome LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(polindrome main.cpp)

install(TARGETS polindrome
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
