#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("khong the cap phat bo nho.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void insertAtPosition(Node** head_ref, int value, int position) {
    Node* newNode = createNode(value);
    if (position == 0) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }

    Node* current = *head_ref;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Vi tri vuot qua do dai danh sach.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}


int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("danh sach lien ket don: ");
    printList(head);

    int value, position;
    printf("Nhap gia tri muon chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon chen: ");
    scanf("%d", &position);

    insertAtPosition(&head, value, position);
    printList(head);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
