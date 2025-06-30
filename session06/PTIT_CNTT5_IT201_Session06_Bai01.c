#include <stdio.h>
void binary(int n){
    if(n >  1){
        binary(n / 2);
    }
    printf("%d", n % 2);
}
int main(){
    int n;
    printf("nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    binary(n);
    return 0;
}