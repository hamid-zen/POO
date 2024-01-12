cmake_minimum_required(VERSION 3.5)

project(tp6_exo2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tp6_exo2 main.cpp resultat.cc date.cc ensembleresultat.cc)
