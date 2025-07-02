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

void deleteHead(Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Danh sach rong, khong co gi de xoa.\n");
        return;
    }

    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next; // Cập nhật head sang phần tử tiếp theo
    free(temp); // Giải phóng bộ nhớ node cũ
}


int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("danh sach lien ket don: ");
    printList(head);

    deleteHead(&head);
    printList(head);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
