#include <stdio.h>
int binarySearch(int arr[], int n, int search) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == search) {
            return mid + 1;
        }
        if (arr[mid] < search) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
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
    sort(arr, n);
    int value;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &value);
    int result = binarySearch(arr, n, value);
    if (result != -1) {
        printf("Phan tu vi tri thu: %d\n", result);
    } else {
        printf("Khong ton tai phan tu\n");
    }
    //độ phức tạp thời gian của thuật toán là O(log n)
    return 0;
}
