#include <stdio.h>
int main(){
    int arr[] = {1,2,3,4,5,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    int flag= -1;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(arr[i] > arr[j]){
                flag =1;
            } else{
                flag = -1;
                break;
            }
        }
        if(flag == 1){
            printf("%d  ", arr[i]);
        }
    }
    printf("%d", arr[n-1]);
    return 0;
}