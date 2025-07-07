//
// Created by DELL on 7/4/2025.
//
#include <stdio.h>
#include <stdlib.h>
// triển khai chương trình thêm phần tử vào đầu danh sách liên kết đôi

// tạo cấu trúc Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;
// TẠO HÀM THÊM VÀO ĐẦU
Node* insertAtHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    // nếu danh sách không rỗng
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;// lúc này newNode đóng vai trò là head
}
// tạo hàm thêm node vào cuối danh sách
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next=NULL;
    newNode->prev=NULL;
    // nếu danh sách đang rỗng thì node mới chính là node đầu tiên
    if (head==NULL) {
        return newNode;
    }
    Node* temp = head;
    while(temp->next!=NULL) {
        temp = temp->next; // 4
    }
    // temp sẽ là phần tử cuối
    newNode->prev = temp;
    temp->next = newNode;
    return head;


}
// hiển thị danh sách liên kết đơn
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}
int main() {
    Node* head=NULL;
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);

    printList(head);
}