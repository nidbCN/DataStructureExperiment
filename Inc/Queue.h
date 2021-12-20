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

/*
 * Create a Queue
 * T: Type of each element;
 * return Queue*.
 */
#define createQueue(T) (_createQueue(sizeof(T)))

/*
 * Create a Queue
 * size: Size of each element;
 * return Queue*.
 */
Queue *_createQueue(size_t size);

/*
 * Get element out the queue
 * queue: Queue struct pointer;
 * return void*.
 */
void *dequeue(Queue *queue);

/*
 * Put element in the queue
 * queue: Queue struct pointer;
 * data: Pointer to data;
 * return void.
 */
void enqueue(Queue *queue, void *data);

/*
 * Clear all elements
 * queue: Queue struct pointer;
 * return void.
 */
void clear(Queue *queue);

#endif //QUEUE_H
