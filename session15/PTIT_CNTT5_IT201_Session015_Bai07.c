#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return q->rear < q->front;
}

bool enqueue(Queue *q, int value) {
    if (q->rear + 1 >= MAX) return false;
    q->rear++;
    q->data[q->rear] = value;
    return true;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int value = q->data[q->front];
    q->front++;
    return value;
}

bool isIncreasingByOne(Queue *q) {
    if (q->rear - q->front < 1) return false;

    int prev = dequeue(q);
    while (!isEmpty(q)) {
        int curr = dequeue(q);
        if (curr - prev != 1) return false;
        prev = curr;
    }
    return true;
}

int main() {
    Queue q;
    initQueue(&q);

    int n, x;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    printf("Nhap %d so nguyen duong: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    if (isIncreasingByOne(&q)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}