#include <stdio.h>
int main(){
    int arr[] = {3, 5, 8, 1, 6, 4};
    for(int i = 0; i< sizeof(arr)/sizeof(arr[0]) -1;i++){
        for (int j = 0; j < sizeof(arr)/sizeof(arr[0]) - 1 - i; j++) {
            if(arr[j] > arr[j +1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return 0;
}
//Độ phức tạp về thời gian = 0(n^2)
//Độ phức tạp về không gian = 0(1)