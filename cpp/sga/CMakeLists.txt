cmake_minimum_required(VERSION 3.5)

project(sga LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sga main.cpp)

install(TARGETS sga
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
