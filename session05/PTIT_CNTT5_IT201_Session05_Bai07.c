#include <stdio.h>
int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(){
    int n;
    printf("nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    if(n < 1){
        return 0;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = fibonacci(i);
        printf("%d  ", arr[i]);
    }
    return 0;
}