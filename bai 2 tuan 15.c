#include <stdio.h>
#include <stdlib.h>
/*CẤU TRÚC NODE*/
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;
/*TẠO NODE*/
Node* createNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
/*NHẬP CÂY NHỊ PHÂN (TIỀN TỰ)*/
/* Nhập -1 nếu node rỗng */
Node* inputTree() {
    int x;
    scanf("%d", &x);

    if (x == -1)
        return NULL;
    Node* root = createNode(x);
    root->left = inputTree();
    root->right = inputTree();

    return root;
}
/*KIỂM TRA 2 CÂY CÓ GIỐNG NHAU KHÔNG*/
int isIdentical(Node* t1, Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 == NULL || t2 == NULL)
        return 0;
    if (t1->data != t2->data)
        return 0;
    return isIdentical(t1->left, t2->left) &&
           isIdentical(t1->right, t2->right);
}
/* GIẢI PHÓNG BỘ NHỚ*/
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
/*MAIN*/
int main() {
    Node *T1, *T2;
    printf("Nhap cay nhi phan thu nhat (-1 neu rong):\n");
    T1 = inputTree();
    printf("Nhap cay nhi phan thu hai (-1 neu rong):\n");
    T2 = inputTree();
    if (isIdentical(T1, T2))
        printf("Hai cay nhi phan GIONG NHAU\n");
    else
        printf("Hai cay nhi phan KHONG giong nhau\n");
    freeTree(T1);
    freeTree(T2);
    return 0;
}
