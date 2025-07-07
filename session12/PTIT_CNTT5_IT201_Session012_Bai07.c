#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* insertAtHead(Node* head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(Node* head) {
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    if (head == NULL) return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    head = insertAtHead(head, 6);
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 4);

    printf("truoc khi sap xep:\n");
    printList(head);

    sortList(head);

    printf("sau khi sap xep:\n");
    printList(head);

    freeList(head);
    return 0;
}
