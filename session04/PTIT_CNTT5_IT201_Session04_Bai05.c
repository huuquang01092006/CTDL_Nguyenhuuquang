#include <stdio.h>
int main(){
    int n, value;
    int arr[50];
    printf("nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if(n <=0 || n >=50){
        printf("so luong phan tu khong hop le");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("nhap phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if(arr[j] > arr[j + 1]){
                int temp = arr[j+1];
                arr[j+1]= arr[j];
                arr[j]= temp;
            }
        }
    }
    printf("nhap phan tu muon tim: ");
    scanf("%d", &value);
    int l = 0, r = n - 1, found = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == value) {
            found = 1;
            break;
        } else if (arr[m] < value) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (found)
        printf("Phan tu co trong mang\n");
    else
        printf("Phan tu khong co trong mang\n");
    return 0;
}
