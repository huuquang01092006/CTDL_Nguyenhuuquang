#include <stdio.h>
int main(){
    int arr[] = {2, 3, 5, 77, 3,1,4};
    int max=0;
    int n= sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; ++i) {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    printf("%d", max);
    return 0;
}