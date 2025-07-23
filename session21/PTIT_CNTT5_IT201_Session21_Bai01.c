#include <stdio.h>
#include <stdlib.h>
int Matrix[3][3];
void matrix(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            Matrix[i][j] = 0;
        }
    }
}
void link(int u, int v){
    Matrix[u][v] = 1;
    Matrix[v][u] = 1;
}
void print(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int u, v;
    matrix();
    printf("nhap u: ");
    scanf("%d", &u);
    printf("nhap v: ");
    scanf("%d", &v);
    link(u-1, v-1);
    print();
    return 0;
}