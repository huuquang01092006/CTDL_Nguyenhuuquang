#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct node *next;
}Node;

Node *Link[3];

Node* createNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* addLink(int u, int v){
    Node* newNode = createNode(u);
    newNode->next = Link[v];
    Link[v] = newNode;
    newNode = createNode(v);
    newNode->next = Link[u];
    Link[u] = newNode;
}
void printLink(){
    for(int i = 0; i < 3; i++){
        Node* current = Link[i];
        printf("Dinh thu %d: ", i);
        while(current != NULL){
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
    printf("\n");
}
void addEdge(){
    int u,v;
    printf("nhap u: ");
    scanf("%d", &u);
    printf("nhap v: ");
    scanf("%d", &v);
    addLink(u,v);
    printLink();
}
int main(){
    for(int i = 0; i < 3; i++){
        Link[i] = NULL;
    }
    addEdge();
    addEdge();
    return 0;
}