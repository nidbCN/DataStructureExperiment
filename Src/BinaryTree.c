/*
 * Written by Gaein nidb, 20070241, North University of China.
 * Open source under GPLv3, Free as in Freedom
 */
#include <stdlib.h>
#include <string.h>
#include "../Inc/DataStructureUtil.h"
#include "../Inc/BinaryTree.h"

// Private function defines

// Create binary tree ListNode
TreeNode *createBinaryTreeNode(void *dataInvoke(), size_t size);

// Pre-order from root ListNode
void preOrderNode(TreeNode *node, void *outputInvoke(void *data));

// In-order from root ListNode
void inOrderNode(TreeNode *node, void *outputInvoke(void *data));

// Post-order from root ListNode
void postOrderNode(TreeNode *node, void *outputInvoke(void *data));

// Create binary tree
BinaryTree *createBinaryTree(void *dataInvoke(), size_t size) {
    BinaryTree *newTree = new(BinaryTree);

    newTree->dataSize = size;
    newTree->root = createBinaryTreeNode(dataInvoke, size);

    return newTree;
}

// Create tree ListNode
TreeNode *createBinaryTreeNode(void *dataInvoke(), size_t size) {
    // Invoke function to get data
    void *data = dataInvoke();

    if (data == NULL)
        return NULL;

    TreeNode *newNode = new(TreeNode);

    newNode->data = malloc(size);
    // Copy dataInvoke to ListNode
    memcpy(newNode->data, data, size);

    newNode->leftChild = createBinaryTreeNode(dataInvoke, size);
    newNode->rightChild = createBinaryTreeNode(dataInvoke, size);
    return newNode;
}

void preOrderNode(TreeNode *node, void *outputInvoke(void *data)) {
    if (node != NULL) {
        // Output value of this ListNode
        outputInvoke(node->data);

        preOrderNode(node->leftChild, outputInvoke);
        preOrderNode(node->rightChild, outputInvoke);
    }
}

void preOrderTree(BinaryTree *tree, void *outputInvoke()) {
    if (tree != NULL) {
        preOrderNode(tree->root, outputInvoke);
    }
}

void inOrderNode(TreeNode *node, void *outputInvoke(void *data)) {
    if (node != NULL) {
        inOrderNode(node->leftChild, outputInvoke);

        // Output value of this ListNode
        outputInvoke(node->data);

        inOrderNode(node->rightChild, outputInvoke);
    }
}

void inOrderTree(BinaryTree *tree, void *outputInvoke()) {
    if (tree != NULL) {
        inOrderNode(tree->root, outputInvoke);
    }
}

void postOrderNode(TreeNode *node, void *outputInvoke(void *data)) {
    if (node != NULL) {
        postOrderNode(node->leftChild, outputInvoke);
        postOrderNode(node->rightChild, outputInvoke);

        // Output value of this ListNode
        outputInvoke(node->data);
    }
}

void postOrderTree(BinaryTree *tree, void *outputInvoke()) {
    if (tree != NULL) {
        postOrderNode(tree->root, outputInvoke);
    }
}