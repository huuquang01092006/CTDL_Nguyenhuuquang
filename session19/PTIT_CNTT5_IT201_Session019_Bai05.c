#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Khong du bo nho\n");
        exit(1);
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(Node* root, int target) {
    if (!root) return 0;
    if (root->data == target) return 1;
    return search(root->left, target) || search(root->right, target);
}

int main() {
    Node* root = create(2);
    root->left = create(3);
    root->right = create(4);
    root->left->left = create(5);

    int target = 3;
    printf(search(root, target) ? "true\n" : "false\n");

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}