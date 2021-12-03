#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "BinaryTree.h"

#define T char
#define NODE_COUNT (10)

void *getInput() {
    T input = (T) getchar();

    void *inputPtr = new(T);
    memcpy(inputPtr, &input, sizeof(T));

    return input == EOF ? NULL : (void *) inputPtr;
}

void *output(void *data) {
    printf(" %c", *((T *) data));
}

int main() {
    for (int i = NODE_COUNT; i > 0; --i) {
        printf("%s", "Pre-order create binary tree, please input\n:");

        BinaryTree *tree = createBinaryTree(getInput, sizeof(T));

        printf("\n%s:\n", "Pre-order");
        preOrderTree(tree, output);

        printf("\n%s:\n", "In-order");
        inOrderTree(tree, output);

        printf("\n%s:\n", "Post-order");
        postOrderTree(tree, output);
    }
    return 0;
}
