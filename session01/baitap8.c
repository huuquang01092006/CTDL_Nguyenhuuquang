#include <stdio.h>
int main(){
    int arr[] = {6, 5, 6, 1, 5, 5};
    int max = 0;
    int number1 = arr[0];
    for(int i= 0; i <sizeof(arr)/sizeof(arr[0]); i++){
        int count = 1;
        for (int j = i +1; j < sizeof(arr)/sizeof(arr[0]); ++j) {
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > max){
            max =count;
            number1 = arr[i];
        }
    }
    printf("%d", number1);
    return 0;
}
//Độ phức tạp về thời gian = 0(n^2)
//Độ phức tạp về không gian = 0(1)