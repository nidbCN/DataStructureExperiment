#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
#include "Queue.h"

typedef struct graphNode {
    int number;
    void *data;
    LinkedList *nodeList;
} GraphNode;

typedef struct graph {
    GraphNode **nodeArray;
    int nodeCount;
    size_t size;
} Graph;

#define createGraph(T, cnt, invoke) (_createGraph(cnt, invoke, sizeof(T)))

Graph *_createGraph(int nodeCount, void *nodeDataInvoke(int), size_t size);

Graph *insertEdgeToGraph(Graph *graph, int nodeNum, int nextNodeNum);

void depthFirstSearch(Graph *graph, void *func(int, void*));

void breadthFirstSearch(Graph *graph, void func(int, void*));

#endif //GRAPH_H
