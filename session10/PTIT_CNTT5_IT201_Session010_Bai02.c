#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* insertAtHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}
void printfList(Node* head) {
    Node* current = head;
    int index = 1;
    while (current != NULL) {
        printf("Data %d: %d\n", index, current->data);
        current = current->next;
        index++;
    }
}
int main(void) {

    Node* head = NULL;
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 5);
    printfList(head);
    return 0;
}