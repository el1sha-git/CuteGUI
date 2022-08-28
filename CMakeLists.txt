cmake_minimum_required(VERSION 3.22)
project(CuteGUI)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/parser)
include_directories(src/parser/misc/datastructures)
include_directories(src/xmlparser)

add_executable(CuteGUI
        src/glfw.c)
find_package(glfw3 REQUIRED)

target_link_libraries(CuteGUI glfw3)

add_library(parser SHARED
        src/parser/src/parser.cpp
        src/parser/src/pugixml.cpp
        )

add_executable(Parser
        src/parser/main.cpp)

target_link_libraries(Parser parser)