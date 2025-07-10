
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 30

typedef struct {
    char names[MAX][NAME_LEN + 1];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

int isFull(Queue *q) {
    return q->rear - q->front + 1 >= MAX;
}

void enqueue(Queue *q) {
    if (isFull(q)) {
        printf("Hang doi day. Khong the them khach moi.\n\n");
        return;
    }

    char name[NAME_LEN + 1];
    printf("Nhap ten khach hang (toi da 30 ky tu): ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    q->rear++;
    strcpy(q->names[q->rear], name);

    printf("Da them khach \"%s\" vao hang doi.\n\n", name);
}

void serve(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n\n");
        return;
    }

    printf("Phuc vu khach: %s\n\n", q->names[q->front]);
    q->front++;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi rong.\n\n");
        return;
    }

    printf("Danh sach khach dang cho:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("- %s\n", q->names[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    int choice;
    char buffer[10];

    while (1) {
        printf("Chon thao tac:\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach\n");
        printf("3. Hien thi danh sach khach dang cho\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);

        switch (choice) {
            case 1: enqueue(&q); break;
            case 2: serve(&q); break;
            case 3: displayQueue(&q); break;
            case 4: printf("Ket thuc chuong trinh.\n"); return 0;
            default: printf("Lua chon khong hop le.\n\n"); break;
        }
    }
}
