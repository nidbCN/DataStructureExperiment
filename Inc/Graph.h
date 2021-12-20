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

/*
 * Create a Graph
 * T: Type of each element;
 * cnt: Count of graph nodes;
 * invoke: Get data for node
 *      int index: index of current node;
 * return LinkedList*.
 */
#define createGraph(T, cnt, invoke) (_createGraph(cnt, invoke, sizeof(T)))

/*
 * Create a Graph
 * nodeCount: Count of graph nodes;
 * nodeDataInvoke: Get data for node
 *      int index: index of current node;
 * size: Size of each node data;
 * return Graph*.
 */
Graph *_createGraph(int nodeCount, void *nodeDataInvoke(int), size_t size);

/*
 * Insert an edge into graph
 * nodeNum: Where this edge start;
 * nextNodeNum: Where this edge end;
 * return Graph*.
 */
Graph *insertEdgeToGraph(Graph *graph, int nodeNum, int nextNodeNum);

/*
 * DFS
 * func: A delegate to invoke in dfs.
 * return void.
 */
void depthFirstSearch(Graph *graph, void func(int, void*));

/*
 * BFS
 * func: A delegate to invoke in dfs.
 * return void.
 */
void breadthFirstSearch(Graph *graph, void func(int, void*));

#endif //GRAPH_H
