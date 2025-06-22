#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, m;
    do {
        printf("nhap so luong phan tu cua mang: ");
        scanf("%d", &n);
    } while (n<=0 || n >1000);
    int* arr= (int*) malloc(n*sizeof(int));
    if(arr == NULL){
        printf("khong the cap phat bo nho");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    do {
        printf("nhap so luong phan tu muon them: ");
        scanf("%d", &m);
    } while (m<=0 || m >1000);
    int* newArr = (int*) realloc(arr, (n + m) * sizeof(int));
    if(newArr == NULL){
        printf("khong the cap phat them bo nho");
        free(newArr);
        return 1;
    }

    arr = newArr;
    for (int i = n; i < n + m; ++i) {
        printf("nhap phan tu thu %d: ", i +1);
        scanf("%d", &arr[i]);
    }
    printf("Mang sau khi them phan tu: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}