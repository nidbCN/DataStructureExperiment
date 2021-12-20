#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Graph.h"
#include "DataStructureUtil.h"
#include "Queue.h"


Graph *insertEdgeToGraph(Graph *graph, int nodeNum, int nextNodeNum) {
    addToList(graph->nodeArray[nodeNum - 1].nodeList, nextNodeNum - 1);

    return graph;
}

Graph *createGraph(int nodeCount, void *nodeDataInvoke(int), int *edgeDataInvoke(), size_t size) {
    Graph *newGraph = new(Graph);

    // Create a vertex node array.
    GraphNode **newNodeArray = array(GraphNode*, nodeCount);

    // input node
    for (int i = 0; i < nodeCount; ++i) {
        newNodeArray[i]->number = i;
        memcpy(newNodeArray[i]->data, nodeDataInvoke(i), size);
        newNodeArray[i]->nodeList = createList(int);
    }

    newGraph->nodeCount = nodeCount;
    newGraph->nodeArray = newNodeArray;

    // input edge
    while (true) {
        int *edgeData = edgeDataInvoke();
        if (edgeData == NULL)
            break;

        int node_i = edgeData[0];
        int node_j = edgeData[1];

        if (node_j > nodeCount || node_j > nodeCount) {
            return NULL;
        }

        insertEdgeToGraph(newGraph, node_i, node_j);
    }

    return newGraph;
}

void depthFirstSearchInvoke(Graph *graph, int index, bool *visited, void *func(int)) {
    LinkedList *nodeList = graph->nodeArray[index].nodeList;
    traverseList(nodeList, $(bool, (int listIndex, ListNode* thisNode) {
            int nodeNum = *(int*)thisNode->data;

            if (!visited[nodeNum]) {
            func(nodeNum);
            visited[nodeNum] = true;
    }

            return false;
    }));
}

void depthFirstSearch(Graph *graph, void *func(int)) {
    bool *visited = array(bool, graph->nodeCount);
    memset(visited, false, sizeof(bool) * graph->nodeCount);

    for (int i = 0; i < graph->nodeCount; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            depthFirstSearchInvoke(graph, i, visited, func);
        }
    }
}

void breadthFirstSearchInvoke(Graph *graph, int index, bool *visited, void func(int)) {
    LinkedList *nodeList = graph->nodeArray[index].nodeList;

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

void breadthFirstSearch(Graph *graph, void func(int)) {
    bool *visited = array(bool, graph->nodeCount);
    memset(visited, false, sizeof(bool) * graph->nodeCount);

    for (int i = 0; i < graph->nodeCount; ++i) {
        if (visited[i]) {
            visited[i] = true;
            breadthFirstSearchInvoke(graph, i, visited, func);
        }
    }
}