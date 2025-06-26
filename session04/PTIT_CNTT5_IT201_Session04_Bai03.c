#include <stdio.h>
int main(){
    int n;
    int arr[50];
    printf("nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if(n <=0 || n >=50){
        printf("so luong phan tu khong hop le");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    int min = arr[0];
    for (int i = 0; i < n; ++i) {
        if(min > arr[i]){
            min = arr[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if(min == arr[i]){
            printf("phan tu nho nhat o vi tri %d", i);
            return 1;
        }
    }
    printf("khong tim thay phan tu");
    return 0;
}