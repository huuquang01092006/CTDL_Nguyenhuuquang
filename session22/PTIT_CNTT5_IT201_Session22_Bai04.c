#include <stdio.h>
#include <stdlib.h>
int matrix[100][100];
void createMatrix(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            matrix[i][j] = 0;
        }
    }
}
void linkedMatrix(int u, int v){
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}
void printMatrix(int matrix[100][100], int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int countEdge(int n){
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(matrix[i][j] == 1){
                count++;
            }
        }
    }
    return count/2;
}
int main(){
    int n, edge;
    printf("nhap so dinh cua ma tran: ");
    scanf("%d", &n);
    printf("nhap so cach cua ma tran: ");
    scanf("%d", &edge);
    createMatrix(n);
    for (int i = 0; i < edge; ++i) {
        int u, v;
        printf("nhap cach thu 1 cua dinh: ");
        scanf("%d", &v);
        printf("nhap cach thu 2 cua dinh: ");
        scanf("%d", &u);
        linkedMatrix(u, v);
    }
    printMatrix(matrix, n);
    int count = countEdge(n);
    printf("so cach cua ma tran la: %d", count);
    return 0;
}