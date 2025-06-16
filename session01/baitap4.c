#include <stdio.h>
int main(){
//    c1:
    int sum = 0;
    for(int i = 0; i < n;i++){
        sum += i;
    }
    //Độ phức tạp về không gian = 0(n)
//    c2:
    sum = n * (n + 1) / 2;
    return 0;
}
    //Độ phức tạp về không gian = 0(1)