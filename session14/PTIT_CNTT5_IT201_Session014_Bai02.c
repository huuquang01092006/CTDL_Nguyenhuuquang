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

    for (int i = s.top; i >= 0; i--) {
        printf("%d\n", s.data[i]);
    }

    return 0;
}