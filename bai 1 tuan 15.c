#include <stdio.h>
#include <stdlib.h>

/* CẤU TRÚC NODE*/
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* TẠO NODE*/
Node* createNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

/*  DỰNG CÂY NHỊ PHÂN HOÀN CHỈNH (LEVEL-ORDER)  */
Node* buildTree(int a[], int n, int i) {
    if (i >= n) return NULL;

    Node* root = createNode(a[i]);
    root->left  = buildTree(a, n, 2*i + 1);
    root->right = buildTree(a, n, 2*i + 2);

    return root;
}

/* DUYỆT TRƯỚC (NLR)  */
void truoc(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    truoc(root->left);
    truoc(root->right);
}

/* DUYỆT GIỮA (LNR) */
void giua(Node* root) {
    if (root == NULL) return;
    giua(root->left);
    printf("%d ", root->data);
    giua(root->right);
}

/*  DUYỆT SAU (LRN) */
void duyetsau(Node* root) {
    if (root == NULL) return;
    duyetsau(root->left);
    duyetsau(root->right);
    printf("%d ", root->data);
}

/* HÀM HEAPIFY (MAX-HEAP) */
void heapify(Node* root) {
    if (root == NULL) return;

    Node* largest = root;

    if (root->left && root->left->data > largest->data)
        largest = root->left;

    if (root->right && root->right->data > largest->data)
        largest = root->right;

    if (largest != root) {
        int temp = root->data;
        root->data = largest->data;
        largest->data = temp;

        heapify(largest);
    }
}
/* XÂY DỰNG MAX-HEAP */
void buildHeap(Node* root) {
    if (root == NULL) return;

    buildHeap(root->left);
    buildHeap(root->right);
    heapify(root);
}
/*GIẢI PHÓNG BỘ NHỚ*/
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
/*MAIN*/
int main() {
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(a) / sizeof(a[0]);

    Node* root = buildTree(a, n, 0);
    printf("Duyet truoc: ");
    truoc(root);
    printf("\nDuyet giua: ");
    giua(root);
    printf("\nDuyet sau: ");
    duyetsau(root);
    /* VUN ĐỐNG */
    buildHeap(root);
    printf("\n\nSau khi vun dong (Max-Heap)");
    printf("\nDuyet truoc: ");
    truoc(root);
    freeTree(root);
    return 0;
}
