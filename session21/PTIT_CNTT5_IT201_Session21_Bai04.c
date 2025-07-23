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
    matrix();
    link(1,0);
    link(1,2);
    link(2,0);
    print();
    return 0;
}