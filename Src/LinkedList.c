#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DataStructureUtil.h"
#include "LinkedList.h"

#define lambda(return_type, function_body) \
({ \
      return_type $this function_body \
      $this; \
})
#define $ lambda

/*
 * Traverse the LinkedList
 * list: LinkedList struct pointer;
 * returnHere: Operate the node, and return if it will be continued.
 *      index: Current index of node;
 *      node: Current node struct pointer;
 *      return if it will be continued.
 * return void.
 */
ListNode *traverse(LinkedList *list, bool returnHere(int index, ListNode *node));

LinkedList *createList() {
    LinkedList *list = new(LinkedList);

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    return list;
}

LinkedList *createListFromArray(void **array, int length, size_t size) {
    LinkedList *list = new(LinkedList);

    list->head = NULL;
    list->tail = NULL;

    for (int i = 0; i < length; ++i) {
        addLastToList(list, array[i], size);
    }

    return list;
}

LinkedList *addLastToList(LinkedList *list, void *data, size_t size) {
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

ListNode *findInList(LinkedList *list, void *find, bool compare(void *val, void *node)) {
    return traverse(list, $(bool, (int index, ListNode *thisNode){
            return compare(find, thisNode->data);
    }));

    /*
    for (ListNode *pointer = list->head; pointer != NULL; pointer = pointer->next) {
        bool result = compare(find, pointer->data);

        if (result == true)
            return pointer;
    }

    return NULL;
     */
}

LinkedList *removeInList(LinkedList *list, ListNode *node) {
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

ListNode *traverse(LinkedList *list, bool returnHere(int index, ListNode *node)) {
    ListNode *ptr = list->head;
    int i = 0;
    while (ptr != NULL) {
        if (!returnHere(i, ptr)) {
            return ptr;
        }

        ptr = ptr->next;
        ++i;
    }

    return NULL;
}