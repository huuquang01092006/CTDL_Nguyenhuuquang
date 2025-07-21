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


void preOrder(Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}


int main(){
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    preOrder(root);
    return 0;
}