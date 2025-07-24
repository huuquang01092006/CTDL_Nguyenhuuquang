//ma tran ke
//#include <stdio.h>
//int Matrix[3][3];
//void matrix(){
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++){
//            Matrix[i][j] = i * j;
//        }
//    }
//}
//void link(int u, int v){
//    Matrix[u][v] = 1;
//    Matrix[v][u] = 1;
//}
//void printMatrix(){
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++){
//            printf("%d ", Matrix[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main(){
//    matrix();
//    link(0, 1);
//    printMatrix();
//    return 0;
//}
//danh sach ke
#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

//mang chua danh sach con tro tro toi cac dinh
Node* link[4];

//ham tao node
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//ham tao lien ket
Node* addLink(int u, int v){
//    tao node moi
    Node* newNode = createNode(v);
//    lien ket voi phan tu ban dau
    newNode->next = link[u];
//    newnode thanh node dau tien
    link[u] = newNode;
//    lap lai b1
    newNode = createNode(u);
    newNode->next = link[v];
    link[v] = newNode;
}
void printLink(){
    for(int i = 0; i < 4; i++){
        Node* current = link[i];
        printf("Dinh thu %d: ", i);
        while(current != NULL){
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}
int main(){
    for(int i = 0; i < 4; i++){
        link[i] = NULL;
    }
    addLink(0, 1);
    addLink(1, 2);
    printLink();
    return 0;
}