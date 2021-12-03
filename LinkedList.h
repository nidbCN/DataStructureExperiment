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
LinkedList *create();

/*
 * Add a node at last
 */
LinkedList *addLast(LinkedList *list, void *data, size_t size);

ListNode *find(LinkedList *list, void *find, void *compare(void *val, void *this));

LinkedList *remove(LinkedList *list, ListNode *node);

#endif // LINKED_LIST_H
