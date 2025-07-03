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

Node* deleteMatchingNodes(Node* head, int target) {
    while (head != NULL && head->data == target) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == target) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}

int main(void) {
    Node* head = NULL;
    head = insertAtTail(head, 10);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 30);
    head = insertAtTail(head, 20);
    head = insertAtTail(head, 50);
    printf("danh sach truoc khi xoa:\n");
    printfList(head);
    int x;
    printf("\nnhap so muon xoa: ");
    scanf("%d", &x);
    head = deleteMatchingNodes(head, x);
    printf("danh sach sau khi xoa:\n");
    printfList(head);
    return 0;
}
