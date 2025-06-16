#include <stdio.h>
int main(){
//    c1:
    int arr[] = {6, 5, 6, 1, 3, 4};
    int flag = -1;
    int count = 0;
    for(int i= 0; i <sizeof(arr)/sizeof(arr[0]); i++){
        for (int j = i +1; j < sizeof(arr)/sizeof(arr[0]); ++j) {
            if(arr[i] == arr[j]){
                flag =1;
            }
        }
    }
    printf("%d", flag);
//Độ phức tạp về thời gian = 0(n^2)
//Độ phức tạp về không gian = 0(1)
//    c2:

    return 0;
}