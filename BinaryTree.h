#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct treeNode {
    void* data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
} TreeNode;

typedef struct binaryTree {
    TreeNode *root;
    size_t dataSize;
} BinaryTree;


#define lambda(name),(arg)->(func) void*name(arg){func}

/*
 * Create a binary tree with data which has size 'size'.
 * *dataInvoke: A function provide data of each node;
 * *size: size of node data type;
 */
BinaryTree *createBinaryTree(void *dataInvoke(), size_t size);

/*
 * Pre-order the binary tree.
 * *tree: Tree struct pointer;
 * *outputInvoke(): A function provide output of data;
 */
void preOrderTree(BinaryTree *tree, void* outputInvoke());

/*
 * In-order the binary tree.
 * *tree: Tree struct pointer;
 * *outputInvoke(): A function provide output of data;
 */
void inOrderTree(BinaryTree *tree, void* outputInvoke());

/*
 * Post-order the binary tree.
 * *tree: Tree struct pointer;
 * *outputInvoke(): A function provide output of data;
 */
void postOrderTree(BinaryTree *tree, void* outputInvoke());

#endif
