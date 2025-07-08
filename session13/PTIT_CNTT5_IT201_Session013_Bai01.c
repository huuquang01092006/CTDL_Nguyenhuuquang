#include <stdio.h>

typedef struct {
    int data[5];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int main() {
    Stack s;
    initStack(&s);
}