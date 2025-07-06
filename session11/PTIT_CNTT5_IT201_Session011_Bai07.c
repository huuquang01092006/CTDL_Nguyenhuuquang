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

int insertAtPosition(Node** head_ref, int value, int pos) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (pos == 0 || *head_ref == NULL) {
        newNode->next = *head_ref;
        if (*head_ref) (*head_ref)->prev = newNode;
        *head_ref = newNode;
        return 1;
    }

    Node* temp = *head_ref;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("vi tri khong hop le!\n");
        free(newNode);
        return 0;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    return 1;
}

void printList(Node* head) {
    int index = 1;
    Node* temp = head;
    while (temp != NULL) {
        printf("Node %d: %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }
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

    int val, pos;
    printf("nhap gia tri muon chen: ");
    scanf("%d", &val);
    printf("nhap vi tri muon chen: ");
    scanf("%d", &pos);

    int kq = insertAtPosition(&node1, val, pos);
    if (kq) {
        printList(node1);
    }

    return 0;
}