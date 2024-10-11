#ifndef LIST_H
#define LIST_H

#include <stdint.h>

typedef struct _ListSpan {
    uint32_t spanLength;
    void *data;
    struct _ListSpan *next;
    struct _ListSpan *prev;
} ListSpan;

typedef struct _List {
    int count;
    size_t size;
    ListSpan *firstSpan;
    ListSpan *lastSpan;
} List;

#define createList(T) (_createList(sizoef(T)))

List *_createList(size_t size);

List *addToList(List *list, void *data);

#endif // LIST_H
