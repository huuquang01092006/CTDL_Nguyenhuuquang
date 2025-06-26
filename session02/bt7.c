#include <stdio.h>
int main(){
    int arr[] = {-1, 5,-3,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    int sum, num1, num2;
    printf("nhap tong hai chu so: ");
    scanf("%d", &sum);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(arr[i] + arr[j] == sum){
                printf("so thu nhat la: %d\n", arr[i]);
                printf("so thu hai la: %d", arr[j]);
                return 1;
            }
        }
    }

    return 0;
}