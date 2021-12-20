#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"

#define MAX 100

typedef struct graphNode {
    int number;
    void* data;
    LinkedList *nodeList;
} GraphNode;

typedef struct graph {
    GraphNode *nodeArray;
    int nodeCount;
} Graph;

// 插入边
Graph *insertEdgeToGraph(Graph *graph, int nodeNum, int nextNodeNum);

Graph *createGraph(int nodeCount, void *nodeDataInvoke(int index), int* edgeDataInvoke(), size_t size);

#endif //GRAPH_H
