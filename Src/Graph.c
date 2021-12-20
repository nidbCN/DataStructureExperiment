#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Graph.h"
#include "DataStructureUtil.h"

void depthFirstSearchInvoke(Graph *graph, int index, bool *visited, void *func(int, void *));

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
        newGraph->nodeArray[i]->number = i;
        memcpy(newGraph->nodeArray[i]->data, nodeDataInvoke(i), newGraph->size);
        newGraph->nodeArray[i]->nodeList = createList(int);
    }

    return newGraph;
}

Graph *insertEdgeToGraph(Graph *graph, int nodeNum, int nextNodeNum) {
    addToList(graph->nodeArray[nodeNum - 1]->nodeList, nextNodeNum - 1);

    return graph;
}

void depthFirstSearch(Graph *graph, void *func(int, void *)) {
    bool *visited = array(bool, graph->nodeCount);
    memset(visited, false, sizeof(bool) * graph->nodeCount);

    for (int i = 0; i < graph->nodeCount; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            depthFirstSearchInvoke(graph, i, visited, func);
        }
    }
}

void depthFirstSearchInvoke(Graph *graph, int index, bool *visited, void *func(int, void *)) {
    LinkedList *nodeList = graph->nodeArray[index]->nodeList;
    traverseList(nodeList, $(bool, (int listIndex, ListNode* thisNode) {
            int nodeNum = *(int*)thisNode->data;
            if (!visited[nodeNum]) {
            func(nodeNum);
            visited[nodeNum] = true;
    }
            return false;
    }));
}

void breadthFirstSearch(Graph *graph, void func(int, void *)) {
    bool *visited = array(bool, graph->nodeCount);
    memset(visited, false, sizeof(bool) * graph->nodeCount);

    for (int i = 0; i < graph->nodeCount; ++i) {
        if (visited[i]) {
            visited[i] = true;
            breadthFirstSearchInvoke(graph, i, visited, func);
        }
    }
}

void breadthFirstSearchInvoke(Graph *graph, int index, bool *visited, void func(int, void *)) {
    LinkedList *nodeList = graph->nodeArray[index]->nodeList;

    Queue *queue = createQueue(int);
    enqueue(queue, nodeList->head);

    while (queue->count != 0) {
        dequeue(queue);
        traverseList(nodeList, $(bool, (int i, void* thisNode){
                if (!visited[i]) {
                func(i);
                visited[i] = true;
                dequeue(queue);
        }
                return false;
        }));
    }
}
