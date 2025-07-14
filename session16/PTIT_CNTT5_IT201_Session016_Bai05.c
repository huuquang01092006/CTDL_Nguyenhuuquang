#include <stdio.h>
#include <stdlib.h>

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
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node* taoNut() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho cho nut\n");
        exit(1);
    }
    printf("Nhap so nguyen: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

void themNutVaoHangDoi(Queue* q) {
    Node* newNode = taoNut();
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int loaiBoNutDau(Queue* q) {
    if (q->front == NULL) {
        printf("hang doi rong\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

void hienThiHangDoi(Queue* q) {
    if (q->front == NULL) {
        printf("hang doi rong\n");
        return;
    }
    Node* temp = q->front;
    printf("Hang doi: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Queue* hangDoi = taoHangDoi();

    int giatri1 = loaiBoNutDau(hangDoi);

    themNutVaoHangDoi(hangDoi);
    themNutVaoHangDoi(hangDoi);
    themNutVaoHangDoi(hangDoi);

    hienThiHangDoi(hangDoi);

    int giatri2 = loaiBoNutDau(hangDoi);
    printf("Da lay ra: %d\n", giatri2);

    hienThiHangDoi(hangDoi);

    return 0;
}