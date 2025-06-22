#include <stdio.h>
#include <stdlib.h>
int main(){
    int rows, cols, sumMainDiagonal = 0, sumCrossBrace =0;
    do {
        printf("nhap so luong hang: ");
        scanf("%d", &rows);
        printf("nhap so luong cot: ");
        scanf("%d", &cols);
    } while (rows <=0 || cols <= 0);
    int** arr = (int**) malloc(rows * sizeof(int*));
    if(arr ==NULL){
        printf("khong the cap phat bo nho");
        return 1;
    }
    for (int i = 0; i < rows; ++i) {
        arr[i] = (int*) malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Khong the cap phat cot dong %d\\n", i);
            return 1;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("nhap phan tu dong %d cot %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < rows; ++i) {
        sumMainDiagonal += arr[i][i];
        sumCrossBrace += arr[i][rows - i -1];
    }
    printf("tong duong cheo chinh la: %d\n", sumMainDiagonal);
    printf("tong duong cheo phu la: %d", sumCrossBrace);
    free(arr);
    return 0;
}