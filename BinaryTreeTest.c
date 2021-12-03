#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataStructureUtil.h"
#include "BinaryTree.h"

#define T char

void *getInput() {
    T input = (T) getchar();

    void *inputPtr = new(T);
    memcpy(inputPtr, &input, sizeof(T));

    return (input == '#' || input == '\n') ? NULL : (void *) inputPtr;
}

void *output(void *data) {
    printf(" %c", *((T *) data));
}



int main() {
    message("Pre-order createList binary tree, please input");

    BinaryTree *tree = createBinaryTree(getInput, sizeof(T));

    message("Pre-order");
    preOrderTree(tree, output);

    message("In-order");
    inOrderTree(tree, output);

    message("Post-order");
    postOrderTree(tree, output);
    return 0;
}
