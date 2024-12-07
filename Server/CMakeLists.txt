cmake_minimum_required(VERSION 3.30)
project(Server)

set(CMAKE_CXX_STANDARD 20)

add_executable(Server main.cpp)

target_link_libraries(Server PRIVATE ws2_32)
