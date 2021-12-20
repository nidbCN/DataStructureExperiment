#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Graph.h"
#include "DataStructureUtil.h"

void depthFirstSearchInvoke(Graph *graph, int index, bool *visited, void func(int, void *));

void breadthFirstSearchInvoke(Graph *graph, int index, bool *visited, void func(int, void *));

Graph *_createGraph(int nodeCount, void *nodeDataInvoke(int), size_t size) {
    Graph *newGraph = new(Graph);

    // Create a vertex node array.
    GraphNode **newNodeArray = array(GraphNode*, nodeCount);

    newGraph->nodeCount = nodeCount;
    newGraph->nodeArray = newNodeArray;
    newGraph->size = size;

    // input node
    for (int i = 0; i < newGraph->nodeCount; ++i) {
        GraphNode *newNode = new(GraphNode);

        newNode->number = i;
        newNode->data = malloc(size);
        memcpy(newNode->data, nodeDataInvoke(i + 1), newGraph->size);
        newNode->nodeList = createList(int);

        newGraph->nodeArray[i] = newNode;
    }

    return newGraph;
}

Graph *insertEdgeToGraph(Graph *graph, int nodeNum, int nextNodeNum) {
    int *index = new(int);
    *index = nextNodeNum - 1;

    addToList(graph->nodeArray[nodeNum - 1]->nodeList, (void *) index);

    return graph;
}

void depthFirstSearch(Graph *graph, void func(int, void *)) {
    bool *visited = array(bool, graph->nodeCount);
    memset(visited, false, sizeof(bool) * graph->nodeCount);

    for (int i = 0; i < graph->nodeCount; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            func(i, graph->nodeArray[i]->data);
            depthFirstSearchInvoke(graph, i, visited, func);
        }
    }
}

void depthFirstSearchInvoke(Graph *graph, int index, bool *visited, void func(int, void *)) {
    LinkedList *nodeList = graph->nodeArray[index]->nodeList;
    traverseList(nodeList, $(bool, (int listIndex, ListNode* thisNode) {
            int nodeIndex = *(int*)thisNode->data;
            if (!visited[nodeIndex]) {
            func(nodeIndex, graph->nodeArray[nodeIndex]->data);
            visited[nodeIndex] = true;
            depthFirstSearchInvoke(graph, nodeIndex, visited, func);
    }
            return false;
    }));
}

void breadthFirstSearch(Graph *graph, void func(int, void *)) {
    bool *visited = array(bool, graph->nodeCount);
    memset(visited, false, sizeof(bool) * graph->nodeCount);

    for (int i = 0; i < graph->nodeCount; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            func(i, graph->nodeArray[i]->data);
            breadthFirstSearchInvoke(graph, i, visited, func);
        }
    }
}

void breadthFirstSearchInvoke(Graph *graph, int index, bool *visited, void func(int, void *)) {

    Queue *queue = createQueue(int);

    // first node, storage index to queue
    int *thisNodeIndex = new(int);
    *thisNodeIndex = index;
    enqueue(queue, thisNodeIndex);

    while (queue->count != 0) {
        int dequeueNodeIndex = *(int *) dequeue(queue);
        LinkedList *nodeList = graph->nodeArray[dequeueNodeIndex]->nodeList;

        traverseList(nodeList, $(bool, (int listIndex, ListNode* thisNode) {
                int nodeIndex = *(int*)(thisNode->data ) -1;
                if (!visited[nodeIndex]) {
                func(nodeIndex, graph->nodeArray[nodeIndex]->data);
                visited[nodeIndex] = true;
                int* nodeIndexPtr = new(int);
                *nodeIndexPtr = nodeIndex;
                enqueue(queue, nodeIndexPtr);
        }
                return false;
        }));
    }
}
