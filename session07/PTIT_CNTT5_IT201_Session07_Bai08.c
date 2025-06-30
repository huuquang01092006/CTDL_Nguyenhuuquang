#include <stdio.h>
void sortColumn(int arr[][100], int rows, int colIndex) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (arr[i][colIndex] > arr[j][colIndex]) {
                int temp = arr[i][colIndex];
                arr[i][colIndex] = arr[j][colIndex];
                arr[j][colIndex] = temp;
            }
        }
    }
}
int main() {
    int rows, cols, k;
    printf("Nhap so hang (rows): ");
    scanf("%d", &rows);
    printf("Nhap so cot (cols): ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("So hang hoac cot khong hop le.\n");
        return 1;
    }

    int arr[100][100];

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Nhap chi so cot can sap xep : ");
    scanf("%d", &k);
    k = k - 1;

    if (k < 0 || k >= cols) {
        printf("Chi so cot khong hop le.\n");
        return 1;
    }

    sortColumn(arr, rows, k);

    printf("Mang sau khi sap xep cot %d tang dan:\n", k + 1);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}