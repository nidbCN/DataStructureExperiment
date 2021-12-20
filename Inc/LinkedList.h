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
} LinkedList;

/*
 * Create a new LinkedList
 */
LinkedList *createList();

LinkedList *addToList(LinkedList *list, void *data, size_t size);

/*
 * Add a node at last
 */
LinkedList *addLastToList(LinkedList *list, void *data, size_t size);

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
