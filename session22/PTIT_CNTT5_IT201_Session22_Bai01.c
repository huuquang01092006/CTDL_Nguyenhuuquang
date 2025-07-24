    #include <stdio.h>

    void matrix(int Matrix[100][100]){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                Matrix[i][j] = 0;
            }
        }
    }
    void addlink(int u, int v, int Matrix[100][100]){
        Matrix[u][v] = 1;
        Matrix[v][u] = 1;
    }
    void printMatrix(int Matrix[100][100]){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                printf("%d ", Matrix[i][j]);
            }
            printf("\n");
        }
    }
    int main(){
        int n;
        printf("nhap so nguyen duong bat ki: ");
        scanf("%d", &n);
        int Matrix[n][n];
        matrix(Matrix);
        addlink(0, 1, Matrix);
        addlink(0, 2, Matrix);
        addlink(1, 2, Matrix);
        addlink(3, 2, Matrix);
        addlink(1, 3, Matrix);
        addlink(3, 4, Matrix);
        printMatrix(Matrix);
        return 0;
    }