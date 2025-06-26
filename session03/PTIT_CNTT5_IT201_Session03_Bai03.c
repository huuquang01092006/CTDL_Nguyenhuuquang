#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    int sum =0, count=0;
    double average;
    printf("nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("so luong phan tu khong hop le");
        return 1;
    }
    int* arr= (int*) malloc(n*sizeof(int));
    if(arr == NULL){
        printf("khong the cap phat bo nho");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if(arr[i] % 2 == 0){
            sum+=arr[i];
            count++;
        }
    }
    average = (double) sum / count;
    printf("%.2f", average);
    free(arr);
    return 0;
};
