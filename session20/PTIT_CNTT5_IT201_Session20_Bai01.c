#include <stdio.h>
#include <stdlib.h>
//b1: xac dinh cau truc node
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;;
}Node;
//b2: ham tao node
Node *createNode(){
    int n;
    printf("nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    Node *node = (Node*)malloc(sizeof(Node));
    if(node == NULL){
        printf("Khong the cap nhat bo nho");
        return NULL;
    }
    node->data = n;
    node->left = NULL;
    node->right = NULL;
    return node;
}
//b5: duyet cay de hien thi
void inOder(Node *root){
    if(root == NULL){
        return;
    }
    inOder(root->left);
    printf("%d ", root->data);
    inOder(root->right);
};
int main(){
    //b3: tao goc cay nhi phan
    Node *node1 = createNode();
    Node *node2 = createNode();
    Node *node3 = createNode();
    Node *node4 = createNode();
    //b4: lien ket nhanh cua cay
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    inOder(node1);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    return 0;
}