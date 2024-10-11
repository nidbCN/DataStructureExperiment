#include "List.h"
#include "DataStructureUtil.h"

List *_createList(const size_t size) {
    List *list = new(List);
    list->size = size;
    list->count = 0;

    ListSpan *span = new(ListSpan);
    span->spanLength = 4;
    span->data = malloc(size * span->spanLength);

    list->firstSpan = span;
    list->lastSpan = span;
}

List *addToList(List *list, void *data) {
    int index = list->count;
    ListSpan *spanPtr = list->data;

    // seek to last
    while (index > spanPtr->spanLength) {
        index -= spanPtr->spanLength;
        spanPtr = (ListSpan *) (spanPtr->data += spanPtr->spanLength - 1);
    }
}
