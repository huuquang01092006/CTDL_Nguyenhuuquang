#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) {
        printf("Khong du bo nho\n");
        exit(1);
    }
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int contains(Node* root, int x) {
    if (!root) return 0;
    if (root->data == x) return 1;
    return contains(root->left, x) || contains(root->right, x);
}

int main() {
    Node* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);

    int x = 3;
    printf(contains(root, x) ? "true\n" : "false\n");

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}