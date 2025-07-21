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

int height(Node* r) {
    if (!r) return 0;
    int hL = height(r->left), hR = height(r->right);
    return (hL > hR ? hL : hR) + 1;
}

int main() {
    Node* root = create(2);
    root->left = create(3);
    root->right = create(4);
    root->left->left = create(5);

    printf("Chieu cao cua cay la: %d\n", height(root));

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);
    return 0;
}