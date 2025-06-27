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
    int arr[n];
    for (int i = n-1; i >=0; --i) {
        arr[i] = fibonacci(i);
        printf("%d  ", arr[i]);
    }
    return 0;
}