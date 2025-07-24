#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* adjList[MAX];
bool visited[MAX];

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = adjList[u];
    adjList[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = adjList[v];
    adjList[v] = nodeU;
}

void DFS(int v) {
    visited[v] = true;
    printf("%d ", v);
    Node* temp = adjList[v];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            DFS(temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int n, edge;
    printf("nhap so dinh cua do thi: ");
    scanf("%d", &n);

    printf("nhap so canh cua do thi: ");
    scanf("%d", &edge);

    for (int i = 0; i < n; ++i)
        adjList[i] = NULL;

    for (int i = 0; i < edge; ++i) {
        int u, v;
        printf("nhap dinh thu nhat: ");
        scanf("%d", &u);
        printf("nhap dinh thu hai: ");
        scanf("%d", &v);
        addEdge(u, v);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);
    DFS(start);

    return 0;
}
