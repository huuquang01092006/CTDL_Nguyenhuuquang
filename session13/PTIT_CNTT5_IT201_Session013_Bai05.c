#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

int push(Stack* s, int value) {
    if (isFull(s)) {
        printf("ngan xep day!\n");
        return 0;
    }
    s->data[++(s->top)] = value;
    return 1;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("ngan xep rong!\n");
        return -1;
    }
    return s->data[(s->top)--];
}

void reverseArray(int arr[], int n) {
    Stack s;
    initStack(&s);
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n;

    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    printf("Nhap gia tri cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Mang sau khi dao nguoc: ");
    printArray(arr, n);

    return 0;
}
