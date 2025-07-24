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
int matrix[100][100];
void createMatrix(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            matrix[i][j] = 0;
        }
    }
}
void linkedMatrix(int u, int v){
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}
void printMatrix(int matrix[100][100], int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
void changeList(int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(matrix[i][j] == 1){
                link(i, j);
            }
        }
    }
}
int main(){
    int n, edge;
    printf("nhap so dinh cua ma tran: ");
    scanf("%d", &n);
    printf("nhap so cach cua ma tran: ");
    scanf("%d", &edge);
    createMatrix(n);
    for (int i = 0; i < edge; ++i) {
        int u, v;
        printf("nhap cach thu 1 cua dinh: ");
        scanf("%d", &v);
        printf("nhap cach thu 2 cua dinh: ");
        scanf("%d", &u);
        linkedMatrix(u, v);
    }
    printMatrix(matrix, n);
    changeList(n);
    printList(n);
    return 0;
}