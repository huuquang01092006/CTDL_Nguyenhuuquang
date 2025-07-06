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

void deleteAtPosition(Node** head_ref, int pos) {
    if (*head_ref == NULL || pos < 0) {
        printf("khong the xoa.\n");
        return;
    }

    Node* temp = *head_ref;
    if (pos == 0) {
        *head_ref = temp->next;
        if (*head_ref != NULL)
            (*head_ref)->prev = NULL;
        free(temp);
        return;
    }
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Vị trí vượt quá độ dài danh sách.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void printList(Node* head) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        printf("Node %d: %d\n", index, temp->data);
        temp = temp->next;
        index++;
    }
}

int main() {
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    Node* head = node1;

    int pos;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &pos);

    deleteAtPosition(&head, pos);
    printf("Danh sach sau khi xoa:\n");
    printList(head);

    return 0;
}