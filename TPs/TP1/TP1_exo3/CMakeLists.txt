cmake_minimum_required(VERSION 3.5)

project(TP1_exo3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP1_exo3 main.cpp sequence.cc)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options(-Wall -Wpedantic)
endif()
