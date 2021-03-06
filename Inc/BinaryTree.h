#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct treeNode {
    void *data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
} TreeNode;

typedef struct binaryTree {
    TreeNode *root;
    size_t dataSize;
} BinaryTree;

/*
 * Create a binary tree with data which has size 'size'.
 * *dataInvoke: A function provide data of each ListNode;
 * *size: size of ListNode data type;
 */
BinaryTree *createBinaryTree(void *dataInvoke(), size_t size);

/*
 * Pre-order the binary tree.
 * *tree: Tree struct pointer;
 * *invoke(): A function provide output of data;
 */
void preOrderTree(BinaryTree *tree, void invoke());

/*
 * In-order the binary tree.
 * *tree: Tree struct pointer;
 * *invoke(): A function provide output of data;
 */
void inOrderTree(BinaryTree *tree, void invoke());

/*
 * Post-order the binary tree.
 * *tree: Tree struct pointer;
 * *invoke(): A function provide output of data;
 */
void postOrderTree(BinaryTree *tree, void invoke());

#endif
