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

Node* deleteTail(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
}

int main(void) {

    Node* head = NULL;
    head = insertAtTail(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtTail(head, 40);
    head = insertAtTail(head, 50);
    printfList(head);
    head = deleteTail(head);
    printfList(head);
    return 0;

}