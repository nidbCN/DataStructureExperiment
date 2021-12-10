cmake_minimum_required(VERSION 3.20)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_library(BinaryTree STATIC Src/BinaryTree.c)
add_library(LinkedList STATIC Src/LinkedList.c)
add_library(Graph STATIC Src/Graph.c)
add_library(Sort STATIC Src/Graph.c Src/Sort.c Inc/Sort.h)

include_directories(Inc)

add_executable(BinaryTreeTest Src/BinaryTreeTest.c Src/DataStructureUtil.c)
TARGET_LINK_LIBRARIES(BinaryTreeTest BinaryTree)

add_executable(Contact Src/Contact.c Src/DataStructureUtil.c)
TARGET_LINK_LIBRARIES(Contact LinkedList)