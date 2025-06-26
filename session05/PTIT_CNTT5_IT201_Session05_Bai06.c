#include <stdio.h>
int sum(int arr[], int n){
    if(n < 1){
        return 0;
    }
    return arr[n - 1] + sum(arr, n - 1);
}
int main(){
    int n;
    printf("nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("so luong phan tu khong hop le");
        return 1;
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int result = sum(arr, n);
    printf("tong cac phan tu cua mang la: %d  ", result);
    return 0;
}