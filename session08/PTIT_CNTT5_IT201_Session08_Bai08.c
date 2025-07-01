#include <stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            return i + 1;
        }
    }
    return -1;
}
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
    int choice;
    int n;
    int arr[100];
    do{
        printf("1. Nhap so phan tu va cac phan tu cua mang tu ban phim.\n");
        printf("2. In mang.\n");
        printf("3. Sap xep mang.\n");
        printf("4. Nhap mot gia tri can tim\n");
        printf("5. Thoat\n");
        printf("\n");

        printf("nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("nhap so phan tu cua mang: ");
                scanf("%d", &n);
                printf("nhap cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("Phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                printf("da them phan tu vao mang\n");
                break;
            case 2:
                printf("mang ban dau la: \n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 3:
                insertionSort(arr, n);
                printf("mang sau khi sap xep la: \n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 4:
                int select;
                printf("1. sap xep tuyen tinh\n");
                printf("2. sap xep nhi phan\n");
                printf("3. thoat\n");

                printf("nhap lua chon cua ban: ");
                scanf("%d", &select);
                switch (select) {
                    case 1:
                        int value;
                        printf("Nhap gia tri can tim kiem: ");
                        scanf("%d", &value);
                        int result = linearSearch(arr, n, value);
                        if (result != -1) {
                            printf("Vi tri thu: %d\n", result);
                        } else {
                            printf("Khong ton tai phan tu \n");
                        }
                        break;
                    case 2:
                        int value1;
                        printf("Nhap gia tri can tim kiem: ");
                        scanf("%d", &value1);
                        sort(arr, n);
                        int result1 = binarySearch(arr, n, value1);
                        if (result1 != -1) {
                            printf("Vi tri thu: %d\n", result1);
                        } else {
                            printf("Khong ton tai phan tu \n");
                        }
                        break;
                }
                break;
            default:
                printf("lua chon khong hop le.");
        }
    } while (choice != 5);

    return 0;
}