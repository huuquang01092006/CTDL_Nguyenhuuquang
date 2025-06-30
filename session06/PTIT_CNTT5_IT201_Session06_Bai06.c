#include <stdio.h>
int countingLevels(int n){
    if(n <=1 ){
        return 1;
    }
    return countingLevels(n - 1) + countingLevels(n - 2);
}
int main(){
    int n;
    printf("nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    printf("%d", countingLevels(n));
    return 0;
}