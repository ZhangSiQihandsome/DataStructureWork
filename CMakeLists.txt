cmake_minimum_required(VERSION 3.7)
project(DataStructureWork)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h ReadGraph.h testFunction.h Component.h Path.h ShortestPath.h Edge.h MainHeap.h LazyPrimMST.h IndexMinHeap.h)
add_executable(DataStructureWork ${SOURCE_FILES})