#include <stdio.h>
int printfTower(int n, char alpha, char beta, char gamma){
    if(n == 0){
        return 0;
    }
    printfTower(n - 1, alpha, gamma, beta);
    printf("dia %d di chuyen tu %c sang %c\n", n, alpha, gamma);
    return printfTower(n - 1, beta, alpha, gamma);
}
int main(){
    int n;
    printf("nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    printfTower(n, 'A', 'B', 'C');
    return 0;
}