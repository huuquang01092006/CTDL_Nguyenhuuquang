#include <stdio.h>
#include <stdlib.h>
int Matrix[4][4];
void matrix(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Matrix[i][j] = 0;
        }
    }
}
void link(int u, int v){
    Matrix[u][v] = 1;
    Matrix[v][u] = 1;
}
void print(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    matrix();
    link(0,1);
    link(0,2);
    link(1,2);
    link(2,3);
    print();
    return 0;
}