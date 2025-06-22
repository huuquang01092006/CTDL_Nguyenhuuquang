#include <stdio.h>
#include <stdlib.h>
int main(){
    int rows, cols;
    do {
        printf("so luong hang: ");
        scanf("%d", &rows);
        printf("so luong cot: ");
        scanf("%d", &cols);
    } while (rows <= 0 || cols <= 0);
    int** arr = (int**) malloc(rows * sizeof(int*));
    if(arr == NULL){
        printf("khong the cap phat bo nho");
        return 1;
    }
    int max, min;
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Khong the cap phat cot dong %d\\n", i);
            return 1;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("nhap phan tu dong %d cot %d: ", i, j);
            scanf("%d", &arr[i][j]);
            max = min = arr[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        printf("\n");
        for (int j = 0; j < cols; ++j) {
            if(arr[i][j] > max){
                max = arr[i][j];
            }
            if(arr[i][j] < min){
                min = arr[i][j];
            }
            printf("%d  ", arr[i][j]);
        }
    }
    printf("so lon nhat la: %d", max);
    printf("so nho nhat la: %d", min);
    free(arr);
    return 0;
}