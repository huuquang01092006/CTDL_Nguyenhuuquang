#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
void printfList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main(void) {

    Node* head = NULL;
    head = insertAtTail(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtTail(head, 40);
    head = insertAtTail(head, 50);
    printfList(head);
    int value;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &value);
    head = insertAtTail(head, value);
    printfList(head);
    return 0;
}