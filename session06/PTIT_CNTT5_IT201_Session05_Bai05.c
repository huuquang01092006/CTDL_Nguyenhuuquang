#include <stdio.h>
void displayArr(int arr[], int index, int n,int* max, int* min){
    if(index == n){
        return ;
    }
    if(arr[index] > *max){
        *max = arr[index];
    }
    if(arr[index] < *min){
        *min = arr[index];
    }
    displayArr(arr, index + 1, n, max, min);
}
int main(){
    int n;
    printf("nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int max = arr[0],min = arr[0];
    displayArr(arr, 0, n, &max, &min);
    printf("max la: %d\n", max);
    printf("min la: %d", min);
    return 0;
}