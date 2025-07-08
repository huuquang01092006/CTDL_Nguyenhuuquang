#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int push(Stack* s, int value) {
    if (isFull(s)) return 0;
    s->data[++(s->top)] = value;
    return 1;
}

int pop(Stack* s) {
    if (isEmpty(s)) return 0;
    return s->data[(s->top)--];
}

int calculatePostfix(const char* expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int op2 = pop(&s);
            int op1 = pop(&s);
            int result = 0;

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                default:
                    printf("Toan tu khong hop le: %c\n", ch);
                    return 0;
            }

            push(&s, result);
        }
    }

    return pop(&s);
}

int main() {
    char expr[MAX];

    printf("Nhap bieu thuc hau to: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    int result = calculatePostfix(expr);

    printf("=> Ket qua: %d\n", result);

    return 0;
}
