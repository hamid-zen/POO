cmake_minimum_required(VERSION 3.5)

project(cc_19_20 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cc_19_20 main.cpp horaire.cc message.cc)

target_compile_options(cc_19_20 PRIVATE
  -Wall -Wextra -Wpedantic
)
