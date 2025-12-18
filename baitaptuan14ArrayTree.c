#include<stdio.h>
#define max 100
#define empty -1
/*ARRAY TREE*/
typedef struct{
    int Data[max];
    int size;
}ArrayTree;
void createArrayTree(ArrayTree *T, int n){//Ham khoi tao cay
    T->size = n;
    for (int i = 0; i < n; i++){
        T->Data[i] = empty;
    }
}
int EmptyCheck(ArrayTree T){//Kiem tra cay rong
    return T.Data[0] == empty;
}
int Root (ArrayTree T){//Xac dinh nut goc trong cay
    if (!EmptyCheck(T)){
        return 0;
    }
    else 
        return -1;
}
void addRoot(ArrayTree *T, int x){//Them goc vao cho cay
    T->Data[0] = x;
}
void addLeft(ArrayTree *T, int p, int x){//Them con trai
    int k = 2*p+1;
    if (k < T->size){
        T->Data[k] = x;
    }
}
void addRight(ArrayTree *T, int p, int x){//Them con phai
    int k = 2*p+2;
    if (k < T->size){
        T->Data[k] = x;
    }
}
void NLR(ArrayTree T, int p){//Duyet tien to
    if(T.Data[p] != empty){ //Neu cay khong rong
        printf("%d ", T.Data[p]);
        NLR(T, 2*p+1);
        NLR(T, 2*p+2);
    }
}
void LNR(ArrayTree T, int p){//Duyet trung to
    if(T.Data[p] != empty){ //Neu cay khong rong
        LNR(T, 2*p+1);
        printf("%d ", T.Data[p]);
        LNR(T, 2*p+2);
    }
}
void LRN(ArrayTree T, int p){//Duyet hau to
    if(T.Data[p] != empty){ //Neu cay khong rong
        LRN(T, 2*p+1);
        LRN(T, 2*p+2);
        printf("%d ", T.Data[p]);
    }
}
int main(){
    //Tao cay y het tren anh
    ArrayTree T;
    createArrayTree(&T, 15);
    addRoot(&T, 100);
    addLeft(&T, 0, 5);
    addRight(&T, 0, 10);
    addLeft(&T, 1, 1024);
    addRight(&T, 1, 12);
    addLeft(&T, 2, 21);
    addRight(&T, 2, 22);
    //In duyet tien to
    printf("NLR: ");
    NLR(T, 0);
    printf("\n");
    //In duyet trung to
    printf("LNR: ");
    LNR(T, 0);
    printf("\n");
    //In duyet hau to
    printf("LRN: ");
    LRN(T, 0);
    printf("\n");
    return 0;
}
