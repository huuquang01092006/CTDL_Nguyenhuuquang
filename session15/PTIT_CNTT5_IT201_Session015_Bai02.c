#include <stdio.h>

#define MAX 100

typedef struct {
    int array[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q, int cap) {
    q->front = 0;
    q->rear = -1;
    q->capacity = cap;
}

void enqueueFromInput(Queue *q) {
    int value;
    scanf("%d", &value);

    if (q->rear + 1 >= q->capacity) {
        printf("queue is full\n\n");
        return;
    }

    q->rear++;
    q->array[q->rear] = value;

    printf("queue = {\n");
    printf("   array = [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n   front = %d,\n   rear = %d,\n   capacity = %d\n}\n\n",
           q->front, q->rear, q->capacity);
}

int main() {
    Queue q;
    initQueue(&q, 5);

    printf("queue = {\n   array = [],\n   front = 0,\n   rear = -1,\n   capacity = 5\n}\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        enqueueFromInput(&q);
    }

    enqueueFromInput(&q);

    return 0;
}