#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

bool isPalindrome(const char* str) {
    Stack s;
    initStack(&s);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return false;
        }
    }

    return true;
}

int main() {
    char input[MAX];

    printf("Nhap chuoi: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (isPalindrome(input)) {
        printf("=> Chuoi doi xung n");
    } else {
        printf("=> Khong phai chuoi doi xung \n");
    }

    return 0;
}
