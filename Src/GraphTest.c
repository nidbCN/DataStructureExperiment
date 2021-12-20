#include <stdio.h>
#include "Graph.h"
#include "DataStructureUtil.h"

void *getNodeData(int number) {
    printf("Please input data of node %d:\n", number);
    char *data = new(char);
    scanf("%d", data);
    return (void *) data;
}

int main() {
    int nodeCount;
    printf("%s\n", "Please input the number of nodes:");
    scanf("%d", &nodeCount);
    Graph *graph = createGraph(char, nodeCount, getNodeData);

    int edgeCount;
    printf("%s\n", "Please input the number of edges:");
    scanf("%d", &edgeCount);
    for (int i = 0; i < edgeCount; ++i) {
        int start = 0;
        int end = 0;
        printf("%s", "Please input \"startNode endNode\" of edge:");
        scanf("%d %d", &start, &end);
    }

    printf("%s\n", "DFS:");
    depthFirstSearch(graph, $(void*, (int num, void* data){
            char val = *(char*)data;
            printf("node %d: %c", num, val);
    }));

    breadthFirstSearch(graph, $(void*, (int num, void* data){
            char val = *(char*)data;
            printf("node %d: %c", num, val);
    }));
}