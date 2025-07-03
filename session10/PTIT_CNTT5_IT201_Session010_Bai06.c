#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) return newNode;
    Node* current = head;
    while (current->next != NULL) current = current->next;
    current->next = newNode;
    return head;
}
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
Node* findMiddleNode(Node* head) {
    if (head == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    Node* head = NULL;

    head = insertAtTail(head, 5);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 1);
//    head = insertAtTail(head, 6);
    printList(head);
    Node* middle = findMiddleNode(head);
    if (middle != NULL) {
        printf("phan tu o giua la: %d\n", middle->data);
    } else {
        printf("danh sach rong.\n");
    }

    return 0;
}
