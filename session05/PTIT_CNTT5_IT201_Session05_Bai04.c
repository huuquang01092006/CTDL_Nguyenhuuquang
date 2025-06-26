#include <stdio.h>
int sum(int start, int end){
    if(start > end){
        return 0;
    }
    return start + sum(start + 1, end);
}
int main(){
    int start, end;
    printf("nhap so start: ");
    scanf("%d", &start);
    printf("nhap so end: ");
    scanf("%d", &end);
    if(start <= 0 || end <= 0){
        return 0;
    }
    int result = sum(start, end);
    printf("\n%d", result);
    return 0;
}