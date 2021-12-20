#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct queueNode {
    void *data;
    struct queueNode *prev;
    struct queueNode *next;
} QueueNode;

typedef struct queue {
    QueueNode *head;
    QueueNode *tail;
    int count;
    size_t size;
} Queue;

#define create(T) (_create(sizeof(T)))

Queue *_create(size_t size);

void *dequeue(Queue *queue);

void enqueue(Queue *queue, void *data);

void clear(Queue *queue);

#endif //QUEUE_H
