#include <stdio.h>
int exponentiation(int n){
    if(n == 1){
        return 1;
    }
    return n * exponentiation(n -1);
}
int main(){
    int n;
    printf("nhap so bat ki: ");
    scanf("%d", &n);
    if(n < 0){
        return 0;
    }
    int result = exponentiation(n);
    printf("%d", result);
    return 0;
}