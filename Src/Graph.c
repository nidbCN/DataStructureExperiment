#include <stdio.h>
#include <string.h>
#include "Graph.h"
#include "DataStructureUtil.h"
#include "LinkedList.h"
#include <malloc.h>
#include <stdbool.h>

int visited[MAX];

Graph *insertEdgeToGraph(Graph *graph, int nodeNum, int nextNodeNum) {
    EdgeNode *newNode = new(EdgeNode);

    newNode->next = graph->vertexArray[nextNodeNum - 1].edgeList;

    addToList(graph->vertexArray[nodeNum - 1].edgeList, (void *) newNode, sizeof(EdgeNode));

    return graph;
}

Graph *createGraph(int nodeCount, void *nodeDataInvoke(int index), int *edgeDataInvoke(), size_t size) {
    Graph *newGraph = new(Graph);

    // Create a vertex node array.
    VertexNode newNodeArray[nodeCount];

    newGraph->nodeCount = nodeCount;
    newGraph->vertexArray = newNodeArray;

    // input node
    for (int i = 0; i < nodeCount; ++i) {
        memcpy(&newNodeArray[i], nodeDataInvoke(i), size);
    }

    // input edge
    while (true) {
        void *edgeData = edgeDataInvoke();
        if (edgeData == NULL)
            break;

        int node_i = *(int *) edgeData;
        int node_j = *((int *) edgeData + 1);

        if (node_j > nodeCount || node_j > nodeCount) {
            return NULL;
        }

        insertEdgeToGraph(newGraph, node_i, node_j);
    }

    return newGraph;
}

void depthFirstSearch(Graph *graph, void *func()) {
    bool visited[1000];
}

void depthFirstSearchInvoke(Graph *graph, void *func()) {

}

void breadthFirstSearch() {

}

void dfs(Graph g, int i) {
    EdgeNode *p;
    if (visited[i] == 0) {
        visited[i] = 1;
        printf("顶点%d ", i);
    }
    p = g.vertex[i].firstEdge->next;
    while (p != NULL) {
        if (!visited[p->value]) {
            printf("顶点%d ", p->value);
            visited[p->value] = 1;
            //printf(" 访问%d", p->value);
            dfs(g, p->value);
        }
        p = p->next;
    }
}

void DFS(Graph g) {
    int index;
    for (index = 0; index < graph.nodeCount; ++index) {
        visited[index] = 0;
    }
    printf("开始进行深度优先搜索\n");
    for (index = 0; index < graph.nodeCount; index++) {
        if (!visited[index])
            dfs(g, index);
    }
}

void bfs(Graph g, int i) {
    int j;
    EdgeNode *p;
    //用列队进行bfs
    int queue[MAX];
    // FIFO
    int front, rear;
    front = rear = 0;
    //证明被访问过
    visited[i] = 1;
    queue[rear++] = i; //将访问过的节点加入列队中
    printf("顶点%d ", i);
    while (rear > front) {
        j = queue[front++];
        p = graph.vertex[j].firstEdge;
        while (p) {
            if (visited[p->value] == 0) {
                printf("顶点%d ", p->value);
                queue[rear++] = p->value;
                visited[p->value] = 1;
            }
            p = p->next;
        }
    }
}

void BFS(Graph g) {
    int index;
    for (index = 0; index < graph.nodeCount; ++index) {
        visited[index] = 0;
    }
    printf("开始进行广度优先搜索\n");
    for (index = 0; index < graph.nodeCount; index++) {
        if (!visited[index])
            bfs(g, index);
    }
}

//用来测试输入的图的形状，判断是否与输入的图的形状相同
void print() {
    int index = 0;
    edgeNode *p;
    for (index = 0; index < graph.nodeCount; index++) {
        printf("%d子节点是: ", index);
        p = graph.vertex[index].firstEdge;
        while (p) {
            printf(" %d ", p->value);
            p = p->next;
        }
        puts("");
    }
}

int main() {
    Create();
    DFS(graph);
    puts("");
    BFS(graph);
    puts("");
    //print();
    return 0;
}