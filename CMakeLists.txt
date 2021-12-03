cmake_minimum_required(VERSION 3.20)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructure  BinaryTreeTest.c util.h BinaryTree.c BinaryTree.h )
