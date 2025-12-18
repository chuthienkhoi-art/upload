#include<stdio.h>
#include<stdlib.h>
/*Linhked Tree*/
typedef struct Node{
    int Data;
    struct Node *left;
    struct Node *right;
} Node;
Node* createNode(int x){//Khoi tao
    Node *p = (Node*)malloc(sizeof(Node));
    p->Data = x;
    p->left = NULL;
    p->right= NULL;
    return p;
}
int EmptyCheck(Node *root){//Kiem tra rong
    return root == NULL;
}
void addLeft(Node *p, int x){//Them con trai
    p->left = createNode(x);
}
void addRight(Node *p, int x){//Them con phai
    p->right = createNode(x);
}
void NLR(Node *root){//Duyet tien to
    if(root != NULL){ //Neu cay khong rong
        printf("%d ", root->Data);
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Node *root){//Duyet trung to
    if(root != NULL){ //Neu cay khong rong
        LNR(root->left);
        printf("%d ", root->Data);
        LNR(root->right);
    }
}
void LRN(Node *root){//Duyet hau to
    if(root != NULL){ //Neu cay khong rong
        LRN(root->left);
        LRN(root->right);
        printf("%d ", root->Data);
    }
}
int main(){
    //Nhap cay theo hinh
    Node *root = createNode(100);
    addLeft(root, 5);
    addRight(root, 10);
    addLeft(root->left, 1024);
    addRight(root->left, 12);
    addLeft(root->right, 21);
    addRight(root->right, 22);
    //In ra duyet tien to
    printf("NLR: ");
    NLR(root);
    printf("\n");
    //In ra duyet trung to
    printf("LNR: ");
    LNR(root);
    printf("\n");
    //In ra duyet hau to
    printf("LRN: ");
    LRN(root);
    printf("\n");
    return 0;
}
