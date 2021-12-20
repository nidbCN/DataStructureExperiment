cmake_minimum_required(VERSION 3.10)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_library(BinaryTree STATIC Src/BinaryTree.c)
add_library(LinkedList STATIC Src/LinkedList.c)
add_library(Queue STATIC Src/Queue.c)
add_library(Graph STATIC Src/Graph.c)
add_library(Sort STATIC Src/Sort.c)

include_directories(Inc)

TARGET_LINK_LIBRARIES(Graph Queue)

add_executable(BinaryTreeTest Src/BinaryTreeTest.c Src/DataStructureUtil.c)
TARGET_LINK_LIBRARIES(BinaryTreeTest BinaryTree)

add_executable(Contact Src/Contact.c Src/DataStructureUtil.c)
TARGET_LINK_LIBRARIES(Contact LinkedList)

add_executable(GraphTest Src/GraphTest.c Src/DataStructureUtil.c)
TARGET_LINK_LIBRARIES(GraphTest Graph LinkedList)

add_executable(BookManager Src/BookManager.c Src/DataStructureUtil.c)
TARGET_LINK_LIBRARIES(BookManager Sort)
