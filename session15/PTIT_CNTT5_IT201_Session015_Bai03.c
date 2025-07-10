#include <stdio.h>
#define MAX 100

typedef struct {
    int array[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

int main() {
    Queue queue1;
    initQueue(&queue1, 5);

    printf("Queue = {\n  array = [],\n  front = %d,\n  rear = %d,\n  capacity = %d\n}\n", queue1.front, queue1.rear, queue1.capacity);
    printf("%s\n\n", isEmpty(&queue1) ? "true" : "false");

    Queue queue2;
    initQueue(&queue2, 5);
    queue2.rear = 2;
    queue2.array[0] = 1;
    queue2.array[1] = 2;
    queue2.array[2] = 5;

    printf("Queue = {\n  array = [1, 2, 5],\n  front = %d,\n  rear = %d,\n  capacity = %d\n}\n", queue2.front, queue2.rear, queue2.capacity);
    printf("%s\n", isEmpty(&queue2) ? "true" : "false");

    return 0;
}