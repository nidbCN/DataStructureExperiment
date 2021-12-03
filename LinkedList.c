#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DataStructureUtil.h"
#include "LinkedList.h"

LinkedList *create() {
    LinkedList *list = new(LinkedList);

    list->head = NULL;
    list->tail = NULL;

    return list;
}

LinkedList *addLast(LinkedList *list, void *data, size_t size) {
    ListNode *newNode = new(ListNode);

    newNode->data = malloc(size);
    memcpy(newNode->data, data, size);
    newNode->next = NULL;

    if (list->tail == NULL) {
        newNode->prev = NULL;

        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;

        list->tail->next = newNode;
        list->tail = newNode;
    }

    return list;
}

ListNode *find(LinkedList *list, void *find, void *compare(void *val, void *node)) {
    for (ListNode *pointer = list->head; pointer != list->tail; pointer = pointer->next) {
        bool result = *((bool *) compare(find, pointer->data));

        if (result == true)
            return pointer;
    }

    return NULL;
}

LinkedList *remove(LinkedList *list, ListNode *node) {
    if (node == list->head) {
        list->head = node->next;
        list->head->prev = NULL;
    } else if (node == list->tail) {
        list->tail = node->prev;
        list->tail->next = NULL;
    } else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    free(node);

    return list;
}