cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

project(Vending)

include_directories(src)

add_executable(Vending src/main.cpp src/item.cpp src/vending-machine.cpp)