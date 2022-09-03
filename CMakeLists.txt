cmake_minimum_required(VERSION 3.22)
project(CuteGUI)

set(CMAKE_CXX_STANDARD 17)

add_executable(cgm
        src/cgm/main.cpp
        src/cgm/src/cgm.cpp
        src/cgm/include/config.h)