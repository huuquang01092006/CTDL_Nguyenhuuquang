#include <stdio.h>
int dequy(int rows, int cols,int i, int j){
    if(i >= rows || j >= cols){
        return 0;
    }
    if(i == rows-1 && j == cols-1){
        return 1;
    }
    return dequy(rows, cols, i+1,j)+ dequy(rows, cols, i, j+1);
}
int main(){
    int rows, cols;
    printf("nhap so cot: ");
    scanf("%d", &cols);
    printf("nhap so hang: ");
    scanf("%d", &rows);
    printf("%d", dequy(rows, cols, 0, 0));
    return 0;
}