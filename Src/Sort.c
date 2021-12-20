#include <stddef.h>
#include <memory.h>
#include <stdio.h>
#include <malloc.h>
#include "Sort.h"

void _quickSortInvoke(int **array, int left, int right, size_t, int compare(const void *, const void *));

void _quickSort(void *array, int count, size_t size, int compare(const void *, const void *)) {
    int leftPtr = 0;
    int rightPtr = count - 1;

    _quickSortInvoke(array, leftPtr, rightPtr, size, compare);
}

void _quickSortInvoke(int **array, int left, int right, size_t size, int compare(const void *, const void *)) {

    // complete
    if (left >= right)
        return;

    // record origin value
    int originLeft = left;
    int originRight = right;

    // convert to long and add memory offset
    void *base = malloc(size);
    memcpy(base, (void *) ((long) array + left * size), size);

    while (left < right) {
        // right
        while (left < right && compare(base, (void *) ((long) array + right * size)) <= 0) {
            right--;
        }
        memcpy((void *) ((long) array + left * size), (void *) ((long) array + right * size), size);

        // left
        while (left < right && compare(base, (void *) ((long) array + left * size)) >= 0) {
            left++;
        }
        memcpy((void *) ((long) array + right * size), (void *) ((long) array + left * size), size);
    }
    // put base number back
    memcpy((void *) ((long) array + left * size), base, size);

    _quickSortInvoke(array, originLeft, left - 1, size, compare);
    _quickSortInvoke(array, left + 1, originRight, size, compare);
}