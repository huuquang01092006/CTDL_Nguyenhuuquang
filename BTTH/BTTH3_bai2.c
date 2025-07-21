#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL 100

typedef struct Node {
    char url[MAX_URL];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

// Khởi tạo stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Kiểm tra stack rỗng
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Đẩy vào stack
void push(Stack* stack, const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Lấy phần tử khỏi stack
char* pop(Stack* stack) {
    if (isEmpty(stack)) return NULL;
    Node* temp = stack->top;
    stack->top = temp->next;
    char* url = (char*)malloc(MAX_URL);
    strcpy(url, temp->url);
    free(temp);
    return url;
}

// Xóa toàn bộ stack
void clearStack(Stack* stack) {
    while (!isEmpty(stack)) {
        free(pop(stack));
    }
}

// Hiển thị stack từ trên xuống
void showHistory(Stack* stack) {
    Node* current = stack->top;
    int count = 1;
    while (current != NULL) {
        printf("%d. %s\n", count++, current->url);
        current = current->next;
    }
}
int main() {
    Stack backStack, forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);
    char url[MAX_URL];
    int choice;

    do {
        printf("\n—————————— BROWSER HISTORY MANAGER ——————————\n");
        printf("1. VISIT: Truy cập một website mới\n");
        printf("2. BACK: Quay lại trang trước đó\n");
        printf("3. FORWARD: Tiến tới trang tiếp theo\n");
        printf("4. HISTORY: Hiển thị danh sách lịch sử\n");
        printf("5. THOÁT: Thoát chương trình\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhập URL: ");
                fgets(url, MAX_URL, stdin);
                url[strcspn(url, "\n")] = 0;
                push(&backStack, url);
                clearStack(&forwardStack);
                printf("Đã truy cập: %s\n", url);
                break;
            case 2:
                if (!isEmpty(&backStack)) {
                    char* prevURL = pop(&backStack);
                    push(&forwardStack, prevURL);
                    printf("Quay lại: %s\n", prevURL);
                    free(prevURL);
                } else {
                    printf("Không có trang trước đó.\n");
                }
                break;
            case 3:
                if (!isEmpty(&forwardStack)) {
                    char* nextURL = pop(&forwardStack);
                    push(&backStack, nextURL);
                    printf("Tiến tới: %s\n", nextURL);
                    free(nextURL);
                } else {
                    printf("Không có trang tiếp theo.\n");
                }
                break;
            case 4:
                printf("\nLịch sử truy cập (mới nhất trước):\n");
                showHistory(&backStack);
                break;
            case 5:
                printf("Đang thoát chương trình...\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }

    } while (choice != 5);

    clearStack(&backStack);
    clearStack(&forwardStack);
    return 0;
}
