#include <stdio.h>
int main(){
    int arr[] = {2, 3, 5, 77, 3,1,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    int position=0;
    printf("nhap vi tri muon xoa: ");
    scanf("%d", &position);
    if(position >= n){
        printf("vi tri khong ton tai trong mang");
        return 1;
    }
    for (int i = position; i < n -1; ++i) {
        arr[i] = arr[i + 1];
    }
    --n;
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    return 0;
}