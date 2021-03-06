#ifndef UTIL_H
#define UTIL_H

#include <malloc.h>
#include <stdbool.h>

#define lambda(return_type, function_body) \
({ \
      return_type $this function_body \
      $this; \
})
#define $ lambda

#define new(T) ((T*)malloc(sizeof(T)))
#define array(T, length) ((T*)malloc(sizeof(T) * (length)))

/*
 * num 是奇数
 */
bool isOdd(int num);

/*
 * num 是偶数
 */
bool isEven(int num);

#endif // UTIL_H
