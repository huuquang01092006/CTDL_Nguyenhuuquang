#include <stdio.h>
int main(){
    int arr[] = {2, 3, 5, 77, 3,1,4};
    int num = 0;
    int count=0;
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("nhap so muon dem:");
    scanf("%d", &num);

    for (int i = 0; i < n; ++i) {
        if(arr[i] == num){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}