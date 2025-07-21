#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("cap phat bo nho khong thanh cong");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//in-order(N-L-R)
void inOrder(Node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}


int main(){
    int n;
    printf("nhap gia tri cua root: ");
    scanf("%d", &n);
    Node *root = createNode(n);
    printf("data:");
    inOrder(root);
    printf("\n");
    printf("left->NULL\n");
    printf("right->NULL");
    return 0;
}