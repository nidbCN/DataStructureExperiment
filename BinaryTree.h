#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct treeNode {
    void* data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
} TreeNode;

typedef struct binaryTree {
    TreeNode root;
    size_t dataSize;
} BinaryTree;

#endif
