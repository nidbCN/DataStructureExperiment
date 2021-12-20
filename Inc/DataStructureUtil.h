#ifndef UTIL_H
#define UTIL_H

#define new(T) ((T*)malloc(sizeof(T)))

#include <stdbool.h>

/*
 * num 是奇数
 */
bool isOdd(int num);

/*
 * num 是偶数
 */
bool isEven(int num);

#endif // UTIL_H
