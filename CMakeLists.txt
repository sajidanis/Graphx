#cmake_minimum_required(VERSION 3.28)
#project(Graphx)
#
#set(CMAKE_CXX_STANDARD 23)
#
#include_directories(${CMAKE_SOURCE_DIR}/Node)
#include_directories(${CMAKE_SOURCE_DIR}/DataStructures)
#include_directories(${CMAKE_SOURCE_DIR}/util)
#include_directories(${CMAKE_SOURCE_DIR}/Graph)
#
#add_executable(Graphx main.cpp
#        Node/Node.h
#        DataStructures/BaseStructure.h
#        DataStructures/AdjacencyList.h
#        Node/Edge.h
#        Graph/SimpleGraph.h
#        Graph/BaseGraph.h
#        util/GraphRepresentation.h
#        DataStructures/AdjacencyMatrix.h
#        Node/EdgeData.h
#        DataStructures/AdjacencyList.cpp
#        Graph/SimpleGraph.cpp)

cmake_minimum_required(VERSION 3.28)
project(Graphx)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/Node)
include_directories(${CMAKE_SOURCE_DIR}/DataStructures)
include_directories(${CMAKE_SOURCE_DIR}/util)
include_directories(${CMAKE_SOURCE_DIR}/Graph)
include_directories(${CMAKE_SOURCE_DIR}/Algorithms)

# Add source files
add_executable(Graphx
        main.cpp
        Node/Node.h
        DataStructures/BaseStructure.h
        DataStructures/AdjacencyList.h
        Node/Edge.h
        Graph/SimpleGraph.h
        Graph/BaseGraph.h
        util/GraphRepresentation.h
        DataStructures/AdjacencyMatrix.h
        Node/EdgeData.h
        Algorithms/BFS.h
        Algorithms/DFS.h
        Algorithms/SSSP.h
        Algorithms/PageRank.h
        util/Constants.h
        Algorithms/TriangleCounting.h
        Algorithms/Color.h
        Algorithms/MIS.cpp.h
)