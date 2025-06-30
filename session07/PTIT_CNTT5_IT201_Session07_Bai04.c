#include <stdio.h>
#include <string.h>
void sortString(char *str) {
    int n = 0;
    while (str[n] != '\0') n++;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
int main(){
    char str[50];
    printf("nhap chuoi: ");
    fgets(str, 50, stdin);
    int length = strlen(str);
    while (str[length] != '\0') length++;
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
        length--;
    }
    if (length == 0) {
        printf("Chuoi khong hop le.\n");
        return 1;
    }
    printf("Chuoi truoc khi sap xep: %s\n", str);

    sortString(str);

    printf("Chuoi sau khi sap xep: %s\n", str);

    return 0;
}