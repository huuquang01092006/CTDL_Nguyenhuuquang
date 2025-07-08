#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

bool push(Stack* s, char ch) {
    if (isFull(s)) return false;
    s->data[++(s->top)] = ch;
    return true;
}

char pop(Stack* s) {
    if (isEmpty(s)) return '\0';
    return s->data[(s->top)--];
}

bool isMatching(char open, char close) {
    return  (open == '(' && close == ')') ||
            (open == '[' && close == ']') ||
            (open == '{' && close == '}');
}

bool checkParentheses(const char* expr) {
    Stack s;
    initStack(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) return false;
            char open = pop(&s);
            if (!isMatching(open, ch)) return false;
        }
    }

    return isEmpty(&s);
}

int main() {
    char expr[MAX];
    printf("Nhap bieu thuc: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    if (checkParentheses(expr)) {
        printf("=> Bieu thuc hop le \n");
    } else {
        printf("=> Bieu thuc khong hop le \n");
    }

    return 0;
}
