#include <stdio.h>
int linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            return i + 1;
        }
    }
    return -1;
}
int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int value;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &value);
    int result = linearSearch(arr, n, value);
    if (result != -1) {
        printf("Vi tri thu: %d\n", result);
    } else {
        printf("Khong ton tai phan tu \n");
    }
    //dộ phức tạp thời gian của thuật toán là O(n)
    return 0;
}