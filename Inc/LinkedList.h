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

/*
 * Add a node at last
 */
LinkedList *addLastToList(LinkedList *list, void *data, size_t size);

ListNode *findInList(LinkedList *list, void *find, void *compare(void *val, void *this));

LinkedList *removeInList(LinkedList *list, ListNode *node);

#endif // LINKED_LIST_H
