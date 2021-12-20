#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include "Sort.h"

/*
 * Sort an array use quickSort
 * T: Type of element;
 * arr: Pointer to first element;
 * cmp: Compare two value, value1 > value2 return1, value1 < value2 return -1.
 *      value1:
 *      value2:
 *      return compare result.
 * return void.
 */
#define quickSort(T, arr, cmp) (_quickSort((void*)(arr), sizeof(arr)/sizeof(T), sizeof(T), cmp))

/*
 * Sort an array use quickSort
 * array: Pointer to first element;
 * count: Length of the array;
 * size: Memory for each element;
 * compare: Compare two value, value1 > value2 return1, value1 < value2 return -1.
 *      value1:
 *      value2:
 *      return compare result.
 * return void.
 */
void _quickSort(void *array, int count, size_t size, int compare(const void *, const void *));

#endif //SORT_H
