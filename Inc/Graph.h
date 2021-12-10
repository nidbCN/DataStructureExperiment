#ifndef GRAPH_H
#define GRAPH_H

#define MAX 100

typedef struct edgeNode {
    void *data;
    struct edgeNode *next;
} EdgeNode;

typedef struct vertexNode {
    EdgeNode *firstEdge;
} VertexNode;

typedef struct graph
{
    VertexNode vertexNodes;
    VertexNode vertex[MAX];
    int n;
    int e;
} Graph;

#endif //GRAPH_H
