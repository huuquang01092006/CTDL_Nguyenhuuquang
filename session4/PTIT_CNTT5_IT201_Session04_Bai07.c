#include <stdio.h>
int main(){
    int n, count = 0;
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
    for (int i = 0; i < n/2; ++i) {
        if(arr[i] == arr[n-i-1]){
            printf("cap so doi xung: (%d,%d)\n", arr[i], arr[i]);
            count = 1;
        }
    }
    if(count != 1){
        printf("phan tu khong co trong mang");
    }
    return 0;
}