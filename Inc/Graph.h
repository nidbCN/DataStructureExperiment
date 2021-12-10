#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"

#define MAX 100

typedef struct edgeNode {
    void *data;
    struct edgeNode *next;
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

#endif //GRAPH_H
