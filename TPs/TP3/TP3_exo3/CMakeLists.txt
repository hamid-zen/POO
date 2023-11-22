cmake_minimum_required(VERSION 3.5)

project(TP3_exo3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP3_exo3 main.cpp carte.cc element.cc taille_position.cc)

target_compile_options(TP3_exo3 PRIVATE
  -Wall -Wextra -Wpedantic
)
