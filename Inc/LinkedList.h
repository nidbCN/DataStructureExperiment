#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct listNode {
    void *data;
    struct listNode *next;
    struct listNode *prev;
} ListNode;

typedef struct linkedList {
    ListNode *head;
    ListNode *tail;
    int count;
    size_t size;
} LinkedList;

#define createList(T) (_createList(sizeof(T)))

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-reserved-identifier"

/*
 * Create a new LinkedList
 */
LinkedList *_createList(size_t size);

#pragma clang diagnostic pop

LinkedList *addToList(LinkedList *list, void *data);

/*
 * Add a node at last
 */
LinkedList *addLastToList(LinkedList *list, void *data);

ListNode *findInList(LinkedList *list, void *find, bool compare(void *, void *));

LinkedList *removeInList(LinkedList *list, ListNode *node);

/*
 * Traverse the LinkedList
 * list: LinkedList struct pointer;
 * returnHere: Operate the node, and return if it will be continued.
 *      index: Current index of node;
 *      node: Current node struct pointer;
 *      return if it will be continued.
 * return void.
 */
ListNode *traverseList(LinkedList *list, bool returnHere(int, ListNode *));

#endif // LINKED_LIST_H
