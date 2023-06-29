cmake_minimum_required(VERSION 3.5)

project(EmployeeRegister LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(EmployeeRegister main.cpp Register.h Register.cpp Record.h Record.cpp)
target_link_libraries(EmployeeRegister -static)

install(TARGETS EmployeeRegister
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
