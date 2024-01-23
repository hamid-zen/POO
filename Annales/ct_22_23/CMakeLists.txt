cmake_minimum_required(VERSION 3.5)

project(ct_22_23 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ct_22_23 main.cpp horaire.cc carnet.cc)

include(GNUInstallDirs)
install(TARGETS ct_22_23
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
