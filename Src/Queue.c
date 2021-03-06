#include <memory.h>
#include "Queue.h"
#include "DataStructureUtil.h"

Queue *_createQueue(size_t size) {
    Queue *newQueue = new(Queue);

    // init queue
    newQueue->head = NULL;
    newQueue->count = 0;
    newQueue->size = size;

    return newQueue;
}

void *dequeue(Queue *queue) {
    QueueNode *node = queue->head;

    queue->head->prev = NULL;
    queue->head = node->next;

    // copy data
    void *result = malloc(queue->size);
    memcpy(result, node->data, queue->size);

    // remove node
    node->prev = NULL;
    node->next = NULL;
    node->data = NULL;
    free(node);

    queue->count--;
    return result;
}

void enqueue(Queue *queue, void *data) {
    QueueNode *node = new(QueueNode);
    node->data = malloc(queue->size);

    // copy data
    memcpy(node->data, data, queue->size);
    node->next = NULL;
    node->prev = queue->tail;

    queue->tail = node;

    // empty queue
    if (queue->count == 0) {
        queue->head = node;
    }

    queue->count++;
}

void clear(Queue *queue) {
    int i = 0;
    QueueNode *ptr = queue->head;

    // free all nodes
    while (i < queue->count) {
        QueueNode *this = ptr;
        ptr = ptr->next;
        ++i;

        this->next = NULL;
        this->prev = NULL;
        this->data = NULL;
        free(this);
    }

    // free queue
    queue->head = NULL;
    queue->tail = NULL;
    free(queue);
}