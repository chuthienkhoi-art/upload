#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
};
/* Tao node */
struct Node* createNode(int v)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->value = v;
    p->left = NULL;
    p->right = NULL;
    return p;
}
/* Kiem tra cay rong */
int isEmpty(struct Node* root)
{
    return root == NULL;
}
/* Xoa rong cay (de quy) */
void xoarong(struct Node** t)
{
    if (*t == NULL) return;

    xoarong(&((*t)->left));
    xoarong(&((*t)->right));
    free(*t);
    *t = NULL;
}
/* Chen node vao BST */
void insert(int val, struct Node** t)
{
    if (*t == NULL)
    {
        *t = createNode(val);
    }
    else if (val < (*t)->value)
    {
        insert(val, &((*t)->left));
    }
    else if (val > (*t)->value)
    {
        insert(val, &((*t)->right));
    }
}
/* Tim kiem node */
struct Node* search(int val, struct Node* t)
{
    if (t == NULL)
        return NULL;

    if (val < t->value)
        return search(val, t->left);
    else if (val > t->value)
        return search(val, t->right);
    else
        return t;
}
/* Duyet truoc (NLR) */
void duyettruoc(struct Node* t)
{
    if (t == NULL) return;
    printf("%d ", t->value);
    duyettruoc(t->left);
    duyettruoc(t->right);
}
/* Duyet giua (LNR) */
void duyetgiua(struct Node* t)
{
    if (t == NULL) return;
    duyetgiua(t->left);
    printf("%d ", t->value);
    duyetgiua(t->right);
}
/* Duyet sau (LRN) */
void duyetsau(struct Node* t)
{
    if (t == NULL) return;
    duyetsau(t->left);
    duyetsau(t->right);
    printf("%d ", t->value);
}
/* Ham main */
int main()
{
    struct Node* root = NULL;
    insert(5, &root);
    insert(6, &root);
    insert(3, &root);
    insert(8, &root);
    insert(7, &root);
    insert(4, &root);
    insert(2, &root);
    printf("Duyet cay thu tu truoc: ");
    duyettruoc(root);
    printf("\n");
    printf("Duyet cay thu tu giua: ");
    duyetgiua(root);
    printf("\n");
    printf("Duyet cay thu tu sau: ");
    duyetsau(root);
    printf("\n");
    struct Node* n1 = search(4, root);
    struct Node* n2 = search(9, root);
    if (n1 != NULL)
        printf("Node co gia tri = 4 la %d\n", n1->value);
    if (n2 == NULL)
        printf("Khong tim thay node co gia tri = 9\n");
    xoarong(&root);
    if (isEmpty(root))
        printf("Cay da bi xoa rong\n");

    return 0;
}
