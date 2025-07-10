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

int dequeue(Queue *q) {
    if (q->rear < q->front) {
        printf("queue is empty\n\n");
        return -1;
    }

    int value = q->array[q->front];
    q->front++;

    printf("return value = %d;\n", value);

    printf("Queue = {\n");
    printf("  array = [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n  front = %d,\n  rear = %d,\n  capacity = %d\n}\n\n",
           q->front, q->rear, q->capacity);

    return value;
}

int main() {
    Queue queue1;
    initQueue(&queue1, 5);

    printf("Queue = {\n  array = [],\n  front = %d,\n  rear = %d,\n  capacity = %d\n}\n", queue1.front, queue1.rear, queue1.capacity);
    dequeue(&queue1);

    Queue queue2;
    initQueue(&queue2, 5);
    queue2.array[0] = 1;
    queue2.array[1] = 2;
    queue2.array[2] = 5;
    queue2.rear = 2;

    printf("Queue = {\n  array = [1, 2, 5],\n  front = %d,\n  rear = %d,\n  capacity = %d\n}\n", queue2.front, queue2.rear, queue2.capacity);
    dequeue(&queue2);

    return 0;
}