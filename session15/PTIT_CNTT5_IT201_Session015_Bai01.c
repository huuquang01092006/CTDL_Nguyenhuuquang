#include <stdio.h>

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

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("hang doi day %d.\n", value);
        return 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    return 1;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("hang doi trong.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue myQueue;

    initQueue(&myQueue);
    printf("hang doi da duoc khoi tao.\n");
    printf("chi so Front: %d\n", myQueue.front);
    printf("chi so Rear: %d\n", myQueue.rear);

    int elementToAdd = 10;
    if (enqueue(&myQueue, elementToAdd)) {
        printf("da them phan tu %d vao hang doi.\n", elementToAdd);
    }

    printQueue(&myQueue);
    printf("chi so Front: %d\n", myQueue.front);
    printf("chi so Rear: %d\n", myQueue.rear);

    return 0;
}