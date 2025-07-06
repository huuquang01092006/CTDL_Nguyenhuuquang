#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void searchValue(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            printf("True\n");
            return;
        }
        temp = temp->next;
    }
    printf("False\n");
}


int main() {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    int value;
    printf("Nhap so can tim: ");
    scanf("%d", &value);
    searchValue(node1, value);
    return 0;
}