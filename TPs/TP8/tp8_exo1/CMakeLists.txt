cmake_minimum_required(VERSION 3.18)

project(tp8_exo1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS off)

set(Qt5_DIR  "/usr/lib/x86_64-linux-gnu/qt5")
find_package(Qt5Widgets REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        add_compile_options(-Wall -Wpedantic)
endif()

add_executable(tp8_exo1 main.cpp calcul.cc)

target_link_libraries(tp8_exo1 Qt5::Widgets)
