#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node *createNode(int data){
    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        printf("Khong the cap nhat bo nho");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* Queue[MAX];
int front = 0, rear = 0;
void enqueue(Node* node){
    if(rear < MAX){
        Queue[rear++] = node;
    }
}
Node* dequeue(){
    if(front < rear){
        return Queue[front++];
    }
    return NULL;
}
int isEmpty(){
    return front == rear;
}

void levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    enqueue(root);
    while(!isEmpty()){
        Node* node = dequeue();
        printf("%d ", node->data);
        if(node->left != NULL){
            enqueue(node->left);
        }
        if(node->right != NULL){
            enqueue(node->right);
        }
    }

}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    levelOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    return 0;
}