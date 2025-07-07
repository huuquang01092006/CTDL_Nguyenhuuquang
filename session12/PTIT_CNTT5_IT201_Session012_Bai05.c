#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* insertAtHead(Node *head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

void printList(Node *head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* deleteAllOccurrences(Node* head, int target) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == target) {
            Node* toDelete = curr;
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;

            if (curr->next)
                curr->next->prev = curr->prev;

            curr = curr->next;
            free(toDelete);
        } else {
            curr = curr->next;
        }
    }
    return head;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    head = insertAtHead(head, 1);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);

    printf("danh sach ban dau:\n");
    printList(head);

    int target;
    printf("nhap so muon xoa: ");
    scanf("%d", &target);

    head = deleteAllOccurrences(head, target);

    printf("danh sach sau khi xoa%d:\n", target);
    printList(head);

    freeList(head);
    return 0;
}
