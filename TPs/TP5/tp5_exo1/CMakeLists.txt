cmake_minimum_required(VERSION 3.5)

project(tp5_exo1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tp5_exo1 main.cc echiquier.cc piece.cc position.cc)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options(-Wall -Wpedantic)
endif()
