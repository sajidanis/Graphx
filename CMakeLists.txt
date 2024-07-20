cmake_minimum_required(VERSION 3.28)
project(Graphx)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/Node)
include_directories(${CMAKE_SOURCE_DIR}/DataStructures)

add_executable(Graphx main.cpp
        Node/Node.h
        DataStructures/DataStructure_Interface.h
        DataStructures/AdjacencyList.h
        Node/Edge.h)
