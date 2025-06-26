#include <stdio.h>
#include <string.h>
int palindrome(char str[50], int l, int r){
    if(l >= r){
        return 1;
    }
    if(str[l] != str[r]){
        return 0;
    }
    return palindrome(str, l + 1, r - 1);
}
int main(){
    char str[50];
    printf("nhap chuoi: ");
    fgets(str, 50, stdin);
    str[strlen(str) -1 ] = '\0';
    int len = strlen(str);
    int l = 0, r = len - 1;
    if(palindrome(str, l, r) == 0){
        printf("khong phai chuoi palindrome");
    }else{
        printf("phai chuoi palindrome");
    }
    return 0;
}