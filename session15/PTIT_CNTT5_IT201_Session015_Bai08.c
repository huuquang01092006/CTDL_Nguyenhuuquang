#include <stdio.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 30

typedef struct {
    char name[NAME_LEN + 1];
    int age;
} Customer;

typedef struct {
    Customer data[MAX];
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

void addCustomer(Queue *oldQ, Queue *normalQ) {
    Customer c;

    printf("Nhap ten khach hang: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("Nhap tuoi: ");
    scanf("%d", &c.age);
    getchar();

    if (c.age >= 60) {
        if (isFull(oldQ)) {
            printf("Hang doi nguoi gia da day.\n\n");
        } else {
            oldQ->rear++;
            oldQ->data[oldQ->rear] = c;
            printf("Da them \"%s\" vao hang doi nguoi gia.\n\n", c.name);
        }
    } else {
        if (isFull(normalQ)) {
            printf("Hang doi nguoi tre da day.\n\n");
        } else {
            normalQ->rear++;
            normalQ->data[normalQ->rear] = c;
            printf("Da them \"%s\" vao hang doi nguoi tre.\n\n", c.name);
        }
    }
}

void serveCustomer(Queue *oldQ, Queue *normalQ) {
    if (!isEmpty(oldQ)) {
        Customer c = oldQ->data[oldQ->front];
        oldQ->front++;
        printf("Phuc vu khach: %s (tuoi %d) tu hang doi nguoi gia.\n\n", c.name, c.age);
    } else if (!isEmpty(normalQ)) {
        Customer c = normalQ->data[normalQ->front];
        normalQ->front++;
        printf("Phuc vu khach: %s (tuoi %d) tu hang doi nguoi tre.\n\n", c.name, c.age);
    } else {
        printf("Khong co khach nao trong hang doi.\n\n");
    }
}

void displayQueue(Queue *q, const char *label) {
    printf("%s:\n", label);
    if (isEmpty(q)) {
        printf("  (rong)\n");
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            printf("  - %s (%d tuoi)\n", q->data[i].name, q->data[i].age);
        }
    }
    printf("\n");
}

int main() {
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int choice;
    char buffer[10];

    while (1) {
        printf("Chon thao tac:\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach cho\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);

        switch (choice) {
            case 1: addCustomer(&queueOld, &queueNormal); break;
            case 2: serveCustomer(&queueOld, &queueNormal); break;
            case 3:
                displayQueue(&queueOld, "Hang doi nguoi gia");
                displayQueue(&queueNormal, "Hang doi nguoi tre");
                break;
            case 4: printf("Ket thuc chuong trinh.\n"); return 0;
            default: printf("Lua chon khong hop le.\n\n");
        }
    }
}