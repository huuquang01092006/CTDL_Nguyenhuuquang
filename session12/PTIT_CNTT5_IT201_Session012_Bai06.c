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

int countNodes(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* findMiddle(Node* head) {
    int count = countNodes(head);
    if (count == 0) return NULL;
    int middlePos = count / 2;
    if (count % 2 == 0) middlePos += 1;
    Node* temp = head;
    for (int i = 1; i < middlePos; i++) {
        temp = temp->next;
    }
    return temp;
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
    head = insertAtHead(head, 5);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    printList(head);
    Node* middle = findMiddle(head);
    if (middle != NULL)
        printf("phan tu o giua la: %d\n", middle->data);
    else
        printf("danh sach rong\n");
    freeList(head);
    return 0;
}
