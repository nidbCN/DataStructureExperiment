#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DataStructureUtil.h"
#include "LinkedList.h"

LinkedList *_createLinkedList(size_t size) {
    LinkedList *list = new(LinkedList);

    // init struct
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    list->size = size;

    return list;
}

LinkedList *addToLinkedList(LinkedList *list, void *data) {
    ListNode *newNode = new(ListNode);

    // init list node
    newNode->data = malloc(list->size);
    memcpy(newNode->data, data, list->size);
    newNode->next = list->head;
    newNode->prev = NULL;

    // point tail to new node
    if (list->count == 0) {
        list->tail = newNode;
    }

    // add at head
    list->head = newNode;
    list->count++;

    return list;
}

LinkedList *addLastToLinkedList(LinkedList *list, void *data) {
    ListNode *newNode = new(ListNode);

    // init list node
    newNode->data = malloc(list->size);
    memcpy(newNode->data, data, list->size);
    newNode->next = NULL;

    if (list->count == 0) {
        // empty list
        newNode->prev = NULL;

        list->head = newNode;
        list->tail = newNode;
    } else {
        // normal list
        newNode->prev = list->tail;

        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->count++;

    return list;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"

ListNode *findInLinkedList(LinkedList *list, void *find, bool compare(void *, void *)) {
    return traverseLinkedList(list, $(bool, (int index, ListNode *thisNode){
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

// Not safe
ListNode *getItemUncertainInLinkedList(void *item) {
    return item;
}

ListNode *getItemAtLinkedList(LinkedList *list, int index) {
    return traverseLinkedList(list, $(bool, (int thisIndex, ListNode* thisNode){
                                      return thisIndex == index;
                                      }));
}

#pragma clang diagnostic pop

void *removeInLinkedList(LinkedList *list, ListNode *node) {
    if (node == list->head) {
        // at head
        list->head = node->next;
        list->head->prev = NULL;
    } else if (node == list->tail) {
        // at end
        list->tail = node->prev;
        list->tail->next = NULL;
    } else {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void *ptr = node->data;
    list->count--;

    free(node);

    return ptr;
}

ListNode *traverseLinkedList(const LinkedList *list, const bool continueTraverse(int, ListNode *)) {
    ListNode *ptr = list->head;
    int i = 0;
    while (ptr != NULL) {
        if (!continueTraverse(i, ptr)) {
            return ptr;
        }

        // go next node
        ptr = ptr->next;
        ++i;
    }

    return NULL;
}
