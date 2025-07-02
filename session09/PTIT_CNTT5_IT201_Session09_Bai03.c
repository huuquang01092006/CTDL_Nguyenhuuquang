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

void search(Node* head, int target) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            printf("True\n");
            return;
        }
        current = current->next;
    }
    printf("False\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Danh sach lien ket don: ");
    printList(head);

    int num;
    printf("Nhap so can tim: ");
    scanf("%d", &num);

    search(head, num);

    freeList(head);

    return 0;
}
