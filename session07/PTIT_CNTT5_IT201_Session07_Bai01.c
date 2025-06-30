#include <stdio.h>
int bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main(){
    int n;
    printf("nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d  ", arr[i]);
    }
    return 0;
}