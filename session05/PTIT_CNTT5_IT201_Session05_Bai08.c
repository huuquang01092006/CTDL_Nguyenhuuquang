#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stringToInt(const char *str, int index, int len, int *result) {
    if (index == len) {
        return 1;
    }

    char c = str[index];
    if (!isdigit(c)) {
        return 0;
    }

    *result = (*result) * 10 + (c - '0');
    return stringToInt(str, index + 1, len, result);
}

int main() {
    char input[100];
    printf("Nhap chuoi so: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int result = 0;
    int start = 0;

    int isNegative = 0;
    if (input[0] == '-') {
        isNegative = 1;
        start = 1;
    }

    if (stringToInt(input, start, strlen(input), &result)) {
        if (isNegative) result = -result;
        printf("So nguyen la: %d\n", result);
    } else {
        printf("Input khong hop le\n");
    }

    return 0;
}
