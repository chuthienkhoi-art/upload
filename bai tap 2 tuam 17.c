#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*CAU TRUC NODE CAY NHI PHAN CHO QUYEN SACH*/
typedef struct Node {
    int index;
    char title[50];
    struct Node* left;
    struct Node* right;
} Node;

/*TAO NODE*/
Node* createNode(int index, const char* title) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->index = index;
    strcpy(p->title, title);
    p->left = NULL;
    p->right = NULL;
    return p;
}

/*CHEN NODE */
Node* insert(Node* root, int index, const char* title) {
    if (root == NULL)
        return createNode(index, title);

    if (index < root->index)
        root->left = insert(root->left, index, title);
    else
        root->right = insert(root->right, index, title);

    return root;
}

/*KIEM TRA 2 QUYEN SACH CO GIONG NHAU KHONG*/
int isSameTree(Node* t1, Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    if (t1->index != t2->index)
        return 0;

    if (strcmp(t1->title, t2->title) != 0)
        return 0;

    return isSameTree(t1->left, t2->left) &&
           isSameTree(t1->right, t2->right);
}

/*DUYET TRUOC (DE KIEM TRA)*/
void preorder(Node* root) {
    if (root == NULL) return;

    printf("(%d, %s) ", root->index, root->title);
    preorder(root->left);
    preorder(root->right);
}

/*MAIN*/
int main() {
    Node* book1 = NULL;
    Node* book2 = NULL;

    /*QUYEN SO 1*/
    book1 = insert(book1, 1, "Chapter 1");
    book1 = insert(book1, 2, "Section 1.4");
    book1 = insert(book1, 3, "Section 1.2");

    /*QUYEN SO 2*/
    book2 = insert(book2, 1, "Chapter 1");
    book2 = insert(book2, 2, "Section 1.1");
    book2 = insert(book2, 3, "Section 1.2");

    printf("Cay sach 1 (Preorder): ");
    preorder(book1);
    printf("\n");

    printf("Cay sach 2 (Preorder): ");
    preorder(book2);
    printf("\n");

    /*KIEM TRA COPY*/
    if (isSameTree(book1, book2))
        printf("\nHai cuon sach la ban copy cua nhau\n");
    else
        printf("\nHai cuon sach KHONG phai ban copy cua nhau\n");

    return 0;
}
