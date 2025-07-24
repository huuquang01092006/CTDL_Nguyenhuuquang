#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *arrayList[100];
Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));\
    if(newNode == NULL){
        printf("khong the cap phat bo nho");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node *link(int u,int v){
    Node *newNode = createNode(v);
    newNode->next = arrayList[u];
    arrayList[u] = newNode;
    newNode = createNode(u);
    newNode->next = arrayList[v];
    arrayList[v] = newNode;
}
void printList(int n){
    for(int i = 0; i < n; i++){
        Node* current = arrayList[i];
        printf("Dinh thu %d: ", i);
        while(current != NULL){
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
int main(){
    for (int i = 0; i < 10; ++i) {
        arrayList[i] = NULL;
    }
    int n, edge;
    printf("nhap so luong cac dinh: ");
    scanf("%d", &n);
    printf("nhap so luong cac cach: ");
    scanf("%d", &edge);
    for (int i = 0; i < edge; ++i) {
        int u, v;
        printf("nhap cach thu 1 cua dinh: ");
        scanf("%d", &v);
        printf("nhap cach thu 2 cua dinh: ");
        scanf("%d", &u);
        link(u, v);
    }
    printList(n);
    return 0;
}