#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

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

/*
 * Create a LinkedList
 * T: Type of each element;
 * return LinkedList*.
 */
#define createList(T) (_createList(sizeof(T)))

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-reserved-identifier"

/*
 * Create a LinkedList
 * size: Size of each element;
 * return LinkedList*.
 */
LinkedList *_createList(size_t size);

/*
 * Add a node at the beginning of LinkedList
 * list: LinkedList struct pointer;
 * data: The data pointer;
 * return LinkedList*.
 */
LinkedList *addToList(LinkedList *list, void *data);

/*
 * Add a node at the end of LinkedList
 * list: LinkedList struct pointer;
 * data: The data pointer;
 * return LinkedList*.
 */
LinkedList *addLastToList(LinkedList *list, void *data);

/*
 * Find a node in LinkedList
 * list: LinkedList struct pointer;
 * find: The data you want to find;
 * compare: A delegate that show if the current node is ok.
 *      find: the node you want to find;
 *      this: current node;
 * return ListNode*.
 */
ListNode *findInList(LinkedList *list, void *find, bool compare(void *, void *));

/*
 * Remove a node in LinkedList
 * list: LinkedList struct pointer;
 * node: ListNode to delete;
 * return LinkedList*.
 */
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
