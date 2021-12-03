/*
 * Written by Gaein nidb, 20070241, North University of China.
 * Open source under GPLv3, Free as in Freedom
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BinaryTree.h"

#define new(type) (type*)malloc(sizeof(type))

// Clear tree node
void clear(TreeNode *node) {
    node->leftChild = NULL;
    node->rightChild = NULL;
}

//先序创建二叉树操作
TreeNode *createBinaryTree(void* data, size_t size) {
    BinaryTree *newTree =  new(BinaryTree);
    TreeNode *rootNode = new(TreeNode);

    // Copy data to node
    memcpy(rootNode->data, data, size);


    if (c == '#')
        bt = NULL; // 又是因为 bt == NULL 造成的错误，导致调试了一下午
    else {
        bt = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        bt->data = c;
        bt->leftChild = createBinaryTree();
        bt->rightChild = createBinaryTree();
    }
    return bt; // 返回根结点
}

//前序遍历二叉树
void preorder(struct TreeNode *root) {
    if (root != NULL) {
        printf("%c\n", root->data);
        preorder(root->leftChild);
        preorder(root->rightChild);
    }
}

// 中序遍历二叉树
void inorder(struct TreeNode *root) {
    if (root != NULL) {
        inorder(root->leftChild);
        printf("%c\n", root->data);
        inorder(root->rightChild);
    }
}

//后序遍历二叉树

void postorder(struct TreeNode *root) {
    if (root != NULL) {
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%c\n", root->data);
    }
}

int main() {
    int n = 10;
    while (n--) {
        struct TreeNode *t;
        cout << "前序建立二叉树" << endl;
        cout << "请输入ABD#F###CE#G### 或者AB#D##C## " << endl;
        t = createBinaryTree();
        cout << "前序遍历二叉树" << endl;
        preorder(t);
        cout << "中序遍历二叉树" << endl;
        inorder(t);
        cout << "后序遍历二叉树" << endl;
        postorder(t);
        getchar();
    }
    return 0;
}