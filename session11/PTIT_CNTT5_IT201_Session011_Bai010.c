#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* insertAtHead(Node *head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev =NULL;
    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    return newNode;
}
void printList(Node *head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void swapAdjacentPairs(Node* head) {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        current = current->next->next;
    }
}


int main(){
    Node* head = NULL;
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 5);
    printf("truoc khi swap:");
    printList(head);
    swapAdjacentPairs(head);
    printf("sau khi swap:");
    printList(head);
    free(head);
    return 0;
}