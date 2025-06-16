#include <stdio.h>
int main(){
    int arr[] = {6, 5, 6, 1, 6, 4};
    int count =0;
    int n = 6;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        if(n == arr[i]){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
//Độ phức tạp về thời gian = 0(n)
//Độ phức tạp về không gian = 0(1)