cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

project(Vending)

add_executable(Vending main.cpp vending-machine.cpp item.cpp)