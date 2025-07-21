#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Trip {
    int id;
    char destination[100];
    char startDate[20];
    int duration;
} Trip;

typedef struct SNode {
    Trip trip;
    struct SNode *next;
} SNode;

typedef struct DNode {
    Trip trip;
    struct DNode *next;
    struct DNode *prev;
} DNode;

SNode *head = NULL;
DNode *doneHead = NULL;

int checkId(int id) {
    SNode *temp = head;
    while (temp != NULL) {
        if (temp->trip.id == id) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void addTrip() {
    Trip trip;
    do {
        printf("Nhap id: ");
        scanf("%d", &trip.id);
    } while (checkId(trip.id));
    getchar();

    printf("Nhap diem den: ");
    fgets(trip.destination, sizeof(trip.destination), stdin);
    trip.destination[strcspn(trip.destination, "\n")] = '\0';

    printf("Nhap ngay khoi hanh (dd/mm/yyyy): ");
    fgets(trip.startDate, sizeof(trip.startDate), stdin);
    trip.startDate[strcspn(trip.startDate, "\n")] = '\0';

    printf("Nhap thoi gian di (ngay): ");
    scanf("%d", &trip.duration);

    SNode *newNode = (SNode*)malloc(sizeof(SNode));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return;
    }

    newNode->trip = trip;
    newNode->next = head;
    head = newNode;

    printf("Them thanh cong!\n");
}

void displayTrip() {
    SNode *temp = head;
    printf("Danh sach chuyen di:\n");
    if (temp == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    while (temp != NULL) {
        printf("ID: %d | Diem den: %s | Ngay khoi hanh: %s | Thoi gian: %d\n",
               temp->trip.id, temp->trip.destination,
               temp->trip.startDate, temp->trip.duration);
        temp = temp->next;
    }
}

void deleteTrip(int id) {
    SNode *temp = head;
    SNode *prev = NULL;

    while (temp != NULL) {
        if (temp->trip.id == id) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Xoa thanh cong!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Khong thay chuyen di nao\n");
}

void updateTrip() {
    int id;
    printf("Nhap id muon cap nhat: ");
    scanf("%d", &id);
    getchar();

    SNode *temp = head;
    while (temp != NULL) {
        if (temp->trip.id == id) {
            printf("Nhap diem den moi: ");
            fgets(temp->trip.destination, sizeof(temp->trip.destination), stdin);
            temp->trip.destination[strcspn(temp->trip.destination, "\n")] = '\0';

            printf("Nhap ngay khoi hanh moi (dd/mm/yyyy): ");
            fgets(temp->trip.startDate, sizeof(temp->trip.startDate), stdin);
            temp->trip.startDate[strcspn(temp->trip.startDate, "\n")] = '\0';

            printf("Nhap thoi gian di moi (ngay): ");
            scanf("%d", &temp->trip.duration);

            printf("Cap nhat thanh cong!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Khong thay chuyen di nao\n");
}

void markTrip() {
    int id;
    printf("Nhap id chuyen di muon danh dau hoan thanh: ");
    scanf("%d", &id);

    SNode *temp = head;
    SNode *prev = NULL;

    while (temp != NULL) {
        if (temp->trip.id == id) {
            DNode *newNode = (DNode*)malloc(sizeof(DNode));
            if (newNode == NULL) {
                printf("Khong the cap phat bo nho!\n");
                return;
            }

            newNode->trip = temp->trip;
            newNode->next = doneHead;
            newNode->prev = NULL;
            if (doneHead != NULL) doneHead->prev = newNode;
            doneHead = newNode;
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);

            printf("Da danh dau chuyen di!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Khong thay chuyen di nao\n");
}

void displayDoneTrip() {
    DNode *temp = doneHead;
    printf("Danh sach chuyen di da hoan thanh:\n");
    if (temp == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    while (temp != NULL) {
        printf("ID: %d | Diem den: %s | Ngay khoi hanh: %s | Thoi gian: %d\n",
               temp->trip.id, temp->trip.destination,
               temp->trip.startDate, temp->trip.duration);
        temp = temp->next;
    }
}

void sortTrip(){

}

void searchTrip(){
    char destination[100];
    getchar();
    printf("Nhap diem den muon tim kiem: ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = '\0';

    SNode *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->trip.destination, destination) == 0) {
            printf("ID: %d | Diem den: %s | Ngay khoi hanh: %s | Thoi gian: %d\n",
                   temp->trip.id, temp->trip.destination,
                   temp->trip.startDate, temp->trip.duration);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Khong tim thay chuyen di nao\n");
    }
}

int main() {
    int choice, id;

    do {
        printf("\n------MENU------\n");
        printf("1. Them chuyen di moi\n");
        printf("2. Hien thi danh sach chuyen di\n");
        printf("3. Xoa chuyen di\n");
        printf("4. Cap nhat chuyen di\n");
        printf("5. Danh dau chuyen di da hoan thanh\n");
        printf("6. Hien thi danh sach chuyen di da hoan thanh\n");
        printf("7. Tim kiem chuyen di theo id\n");
        printf("8. Thoat chuong trinh\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTrip();
                break;
            case 2:
                displayTrip();
                printf("\n");
                displayDoneTrip();
                break;
            case 3:
                printf("Nhap id muon xoa: ");
                scanf("%d", &id);
                deleteTrip(id);
                break;
            case 4:
                updateTrip();
                break;
            case 5:
                markTrip();
                break;
            case 6:{

                break;
            }
            case 7:{
                searchTrip();
                break;
            }
            case 8:
                printf("Ket thuc!\n");
                break;
            default:
                printf("Khong co lua chon nay\n");
        }
    } while (choice != 8);

    return 0;
}