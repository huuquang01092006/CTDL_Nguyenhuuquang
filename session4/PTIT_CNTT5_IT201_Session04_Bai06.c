#include <stdio.h>
#include <string.h>
struct student{
    int id;
    char name[50];
    int age;
};
int main(){
    int n;
    struct student student[50];
    printf("nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if(n <=0 || n >=50){
        printf("so luong phan tu khong hop le");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        printf("nhap phan tu thu %d\n", i);
        printf("nhap id: ");
        scanf("%d", &student[i].id);
        getchar();
        printf("nhap ten: ");
        fgets(student[i].name, 50, stdin);
        student[i].name[strlen(student[i].name) -1 ] - '\0';
        printf("nhap tuoi: ");
        scanf("%d", &student[i].age);
    }
    int id;
    printf("nhap id sinh vien can tim: ");
    scanf("%d", &id);
    for (int i = 0; i < n; ++i) {
        if(student[i].id == id){
            printf("%s%d\n", student[i].name ,student[i].age);
            return 1;
        }
    }
    printf("khong tim thay sinh vien");
    return 0;
}