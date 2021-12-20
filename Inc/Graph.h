#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"

#define MAX 100

typedef struct edgeNode {
    void *data;
    LinkedList *next;
} EdgeNode;

typedef struct vertexNode {
    EdgeNode *firstEdge;
    LinkedList *edgeList;
} VertexNode;

typedef struct graph {
    VertexNode vertexNodes;
    VertexNode vertex[MAX];

    VertexNode *vertexArray;

    int nodeCount;
    int e;
} Graph;

// 插入边
Graph *insertEdgeToGraph(Graph *graph, int nodeNum, int nextNodeNum);

Graph *createGraph(int nodeCount, void *nodeDataInvoke(int index), int* edgeDataInvoke(), size_t size);

#endif //GRAPH_H
