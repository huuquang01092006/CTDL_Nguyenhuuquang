#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* create(int data) {
    Node* n = malloc(sizeof(Node));
    if (!n) {
        printf("Khong du bo nho\n");
        exit(1);
    }
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void insert(Node* root, int value) {
    if (!root) return;

    Node* n = create(value);
    if (!root->left)
        root->left = n;
    else if (!root->right)
        root->right = n;
    else
        insert(root->left, value);
}

int main() {
    Node* root = create(2);
    root->left = create(3);
    root->right = create(4);
    root->left->left = create(5);

    int value = 6;
    insert(root, value);

    printf("Cay sau khi them %d:\n", value);
    printf("Root: %d\n", root->data);
    printf("Left: %d\n", root->left->data);
    printf("Right: %d\n", root->right->data);
    printf("Left-Left: %d\n", root->left->left->data);
    printf("Left-Right: %d\n", root->left->right ? root->left->right->data : -1);

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}