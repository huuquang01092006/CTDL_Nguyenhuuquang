#include <stdio.h>
int main(){
    int arr[] = {2, 3, 5, 77, 3,1,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    int position=0;
    int value=0;
    printf("nhap vi tri muon sua: ");
    scanf("%d", &position);
    if(position >= n){
        printf("vi tri khong ton tai trong mang");
        return 1;
    }
    printf("nhap gia tri muon sua: ");
    scanf("%d", &value);
    arr[position] = value;
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    return 0;
}