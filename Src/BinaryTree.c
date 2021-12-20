/*
 * Written by Gaein nidb, 20070241, North University of China.
 * Open source under GPLv3, Free as in Freedom
 */
#include <stdlib.h>
#include <string.h>
#include "DataStructureUtil.h"
#include "BinaryTree.h"

// Private function defines

// Create binary tree ListNode
TreeNode *createBinaryTreeNode(void *dataInvoke(), size_t size);

// Pre-order from root ListNode
void preOrderNode(TreeNode *node, void invoke(void *data));

// In-order from root ListNode
void inOrderNode(TreeNode *node, void invoke(void *data));

// Post-order from root ListNode
void postOrderNode(TreeNode *node, void invoke(void *data));

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

void preOrderNode(TreeNode *node, void invoke(void *)) {
    if (node != NULL) {
        // Output value of this ListNode
        invoke(node->data);

        preOrderNode(node->leftChild, invoke);
        preOrderNode(node->rightChild, invoke);
    }
}

void preOrderTree(BinaryTree *tree, void invoke()) {
    if (tree != NULL) {
        preOrderNode(tree->root, invoke);
    }
}

void inOrderNode(TreeNode *node, void invoke(void *)) {
    if (node != NULL) {
        inOrderNode(node->leftChild, invoke);

        // Output value of this ListNode
        invoke(node->data);

        inOrderNode(node->rightChild, invoke);
    }
}

void inOrderTree(BinaryTree *tree, void invoke()) {
    if (tree != NULL) {
        inOrderNode(tree->root, invoke);
    }
}

void postOrderNode(TreeNode *node, void invoke(void *)) {
    if (node != NULL) {
        postOrderNode(node->leftChild, invoke);
        postOrderNode(node->rightChild, invoke);

        // Output value of this ListNode
        invoke(node->data);
    }
}

void postOrderTree(BinaryTree *tree, void invoke()) {
    if (tree != NULL) {
        postOrderNode(tree->root, invoke);
    }
}