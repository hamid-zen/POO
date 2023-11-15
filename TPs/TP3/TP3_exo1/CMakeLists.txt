cmake_minimum_required(VERSION 3.5)

project(TP3_exo1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP3_exo1 main.cpp element.cc taille_position.cc)
