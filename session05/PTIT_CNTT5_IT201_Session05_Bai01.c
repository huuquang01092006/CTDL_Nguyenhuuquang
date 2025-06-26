#include <stdio.h>
int display(int n, int start){
    if(n == 0){
        return 1;
    }
    printf("%d  ", start);
    return display(n - 1, start + 1);
}
int main(){
    int n, start = 1;
    printf("nhap vao so nguyen duong bat ki: ");
    scanf("%d", &n);
    if(n < 0){
        return 0;
    }
    display(n, start);
    return 0;
}