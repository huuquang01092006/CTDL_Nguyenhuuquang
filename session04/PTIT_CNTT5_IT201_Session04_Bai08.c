#include <stdio.h>
int main(){
    int n, value, count = 0;
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
    printf("nhap phan tu muon tim: ");
    scanf("%d", &value);
    for (int i = 0; i < n; ++i) {
        if(value == arr[i]){
            printf("phan tu o vi tri thu %d\n", i);
            count = 1;
        }
    }
    if(count != 1) {
        printf("khong tim thay phan tu");
    }
    return 0;
}