#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int id;
    char title[50];
    int credit;
}Course;
typedef struct SNode{
    Course course;
    struct Node *next;
}SNode;
typedef struct DNode{
    Course course;
    struct DNode *next;
    struct DNode *prev;
}DNode;
SNode *head = NULL;
int checkID(int id){
    SNode *temp = head;
    while(temp != NULL){
        if(temp->course.id == id){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void addCourse(){
    Course course;
    do {
        printf("nhap id: ");
        scanf("%d", &course.id);

    } while (checkID(course.id));
    getchar();
    printf("nhap ten: ");
    fgets(course.title, 50, stdin);
    course.title[strlen(course.title) -1 ] - '\0';
    printf("nhap tin chi: ");
    scanf("%d", &course.credit);
    SNode *newNode = (SNode*)malloc(sizeof(SNode));
    if(newNode == NULL){
        printf("khong the cap phat bo nho");
        return;
    }
    newNode->course = course;
    newNode->next = head;
    head = newNode;
    printf("them thanh cong\n");
}
void displayCourse(){
    SNode *temp = head;
    while(temp != NULL){
        printf("ID: %d | Ten: %s | Tin Chi: %d\n", temp->course.id, temp->course.title, temp->course.credit);
        temp = temp->next;
    }
}
void deleteCourse(){
    int id;
    printf("nhap id khoa hoc cua ban muon xoa: ");
    scanf("%d", &id);
    SNode *temp = head;
    if(temp == NULL){
        printf("khong co khoa hoc nao\n");
        return;
    }
    if(temp->course.id == id){
        head = temp->next;
        free(temp);
    }
}
void updateCourse(){
    int id;
    printf("nhap id khoa hoc cua ban muon cap nhat: ");
    scanf("%d", &id);

}
int main(){
    int choice;
    do {
        printf("----MENU----\n");
        printf("1.Them khoa hoc\n");
        printf("2.Hien thi danh sach khoa hoc\n");
        printf("3.Xoa khoa hoc\n");
        printf("4.Cap nhat thong tin khoa hoc\n");
        printf("5.Danh dau khoa hoc da hoan thanh\n");
        printf("6.Sap xep khoa hoc theo so tin chi\n");
        printf("7.Tim kiem khoa hoc theo ten\n");
        printf("8.Thoat chuong trinh\n");
        printf("\n");
        printf("Nhap lua chon cua ban:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{
                addCourse();
                break;
            }
            case 2:{
                displayCourse();
                break;
            }
            case 3:{
                deleteCourse();
                break;
            }
            case 4:{
                break;
            }
            default:{
                printf("Khong co lua chon nay\n");
            }
        }
    } while (choice != 8);
    return 0;
}