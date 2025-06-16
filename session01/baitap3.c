#include <stdio.h>
int main(){
    int* mallocArray(int n){
        int* arr = (int*)malloc(n * sizeof(int));
        for(int i =0;i < n; i++){
            arr[i] = i;
        }
        return arr;
    }
    return 0;
}
//Độ phức tạp về không gian = 0(n)