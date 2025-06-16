#include <stdio.h>
int main() {
    void printfDouble(int n){
        int i =1;
        while(i < n){
            printf("%d\n", i);
            i *= 2;
        }
    }
    printfDouble(5);
    return 0;
}
//Độ phức tạp về thời gian = 0(log n)