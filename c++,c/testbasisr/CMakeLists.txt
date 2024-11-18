cmake_minimum_required(VERSION 3.5)

project(testbasisr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(testbasisr
    Dier.h
    Dierenbeheer.cpp
    Vogel.h
    Zoogdier.h
    Habitat.h)

include(GNUInstallDirs)
install(TARGETS testbasisr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
