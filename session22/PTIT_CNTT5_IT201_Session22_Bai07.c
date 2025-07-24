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

int queue[MAX];
int front = 0, rear = 0;

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

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

bool isEmpty() {
    return front == rear;
}

void BFS(int start) {
    visited[start] = true;
    enqueue(start);

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        Node* temp = adjList[current];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = true;
                enqueue(temp->data);
            }
            temp = temp->next;
        }
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
    printf("nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}
