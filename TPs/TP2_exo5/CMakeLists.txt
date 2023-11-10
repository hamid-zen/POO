cmake_minimum_required(VERSION 3.5)

project(TP2_exo5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP2_exo5 main.cpp jeu_de_la_vie.cc)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options(-Wall -Wpedantic)
endif()
