#include <stdio.h>
#include <string.h>
#include "Graph.h"
#include "DataStructureUtil.h"
#include <malloc.h>

Graph graph;

int visited[MAX];

Graph* createGraph(int count) {
    Graph* newGraph = new(Graph);

    // Create a vertex node array.
    VertexNode newNodeArray[count];
    memset(newNodeArray, new(VertexNode), sizeof(VertexNode));

    newGraph->nodeCount = count;
    newGraph->vertexArray = newNodeArray;

    return newGraph;
}

void insert(int index, void *data) {
    EdgeNode *newNode = new(EdgeNode);
    newNode->data = data;
    //前插
    newNode->next = graph.vertex[index].firstEdge;
    graph.vertex[index].firstEdge = newNode;
}

void Create() {
    EdgeNode *node;
    int i, j, n, e;
    scanf("%d%d", &n, &e); //输入n 个节点
    graph.nodeCount = n;
    graph.e = e;
    //初始化表头信息
    for (i = 0; i < n; i++) {
        graph.vertex[i].firstEdge = NULL;
    }

    //输入 无向边<i,j>从 0 开始
    while (e--) {
        scanf("%d%d", &i, &j);
        if (i == 0 && j == 0)
            break;
        if (i >= n || j >= n)
            printf("有不存在的点，请重新输入\n");
        insert(i, j);
        insert(j, i);
    }
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