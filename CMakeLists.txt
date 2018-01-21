# cmake_minimum_required(VERSION <specify CMake version here>)
project(BD_pizzeria)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -I/usr/local/include  -lpqxx -lpq")

add_executable(BD_pizzeria main.cpp)