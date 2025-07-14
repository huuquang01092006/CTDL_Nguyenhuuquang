#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* taoHangDoi() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool rong(Queue* q) {
    return q->front == NULL;
}

void them(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho cho nut moi!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rong(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int loaiBo(Queue* q) {
    if (rong(q)) {
        printf("Hang doi rong.\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

int xem(Queue* q) {
    if (rong(q)) {
        printf("Hang doi rong!\n");
        return -1;
    }
    return q->front->data;
}

void giaiPhong(Queue* q) {
    while (!rong(q)) {
        loaiBo(q);
    }
    free(q);
}

int main() {
    Queue* hangDoiCuaToi = taoHangDoi();

    them(hangDoiCuaToi, 10);
    them(hangDoiCuaToi, 20);
    them(hangDoiCuaToi, 30);

    printf("Phan tu dau: %d\n", xem(hangDoiCuaToi));

    printf("Loai bo: %d\n", loaiBo(hangDoiCuaToi));
    printf("Loai bo: %d\n", loaiBo(hangDoiCuaToi));

    printf("Phan tu dau: %d\n", xem(hangDoiCuaToi));

    giaiPhong(hangDoiCuaToi);

    return 0;
}