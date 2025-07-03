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
}
void sort(Node* head) {
    Node* i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
int main(void) {

    Node* head = NULL;
    head = insertAtTail(head, 56);
    head = insertAtTail(head, 34);
    head = insertAtTail(head, 21);
    head = insertAtTail(head, 40);
    head = insertAtTail(head, 50);
    printfList(head);
    printf("\n");
    sort(head);
    printfList(head);
    return 0;

}