#include <stdio.h>

typedef struct {
    int data[5];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int push(Stack* s, int value) {
    if (s->top >= 4) {
        printf("ngan xep da day!\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = value;
    return 1;
}

void printStack(const Stack* s) {
    if (s->top == -1) {
        printf("ngan xep rong!\n");
        return;
    }

    printf("cac phan tu trong ngan xep:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}

int main() {
    Stack s;
    initStack(&s);

    int value;
    printf("nhap 5 so nguyen:\n");
    for (int i = 0; i < 5; i++) {
        printf("phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }

    printStack(&s);

    return 0;
}