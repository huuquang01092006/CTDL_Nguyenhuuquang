#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if(n < 0){
        printf("so luong phan tu khong duoc am");
        return 1;
    } else if(n == 0){
        printf("so luong phan tu phai lon hon 0");
        return 1;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("khong the cap phat bo nho");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("phan tu thu %d: \n", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        printf("%d    ", arr[i]);
    }
    free(arr);
    return 0;
}