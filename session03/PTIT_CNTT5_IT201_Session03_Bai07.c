#include <stdio.h>
int main() {
    int rows, cols;
    printf("nhap so hang: ");
    scanf("%d", &rows);
    printf("nhap so cot: ");
    scanf("%d", &cols);
    if(rows <= 0 ||  rows > 1000 ) {
        printf("So hang khong hop le.\n");
        return 1;
    }else if (cols <= 0 || cols > 1000)
    {
        printf("so cot khong hop le.\n");
        return 1;
    }

    int array[rows][cols];
    printf("Nhap cac phan tu cua mang:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("array[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    int k;
    printf("nhap hang can tinh tong : ");
    scanf("%d", &k);
    k--;
    if(k < 0 || k >= rows) {
        printf("Hang can tinh khong ton tai.\n");
        return 1;
    }
    int sum = 0;
    for(int j = 0; j < cols; j++) {
        sum += array[k][j];
    }
    printf("Tong cua hang %d la: %d\n", k +1, sum);
    return 0;
}