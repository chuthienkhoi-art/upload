#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*CAU TRUC CAY TONG QUAT (BOOK TREE)*/
typedef struct Node {
    int id;                     // ma muc
    char title[50];             // tieu de
    int pages;                  // so trang
    struct Node* firstChild;    // con dau
    struct Node* nextSibling;   // anh em ke
} Node;
/*TAO NODE*/
Node* createNode(int id, const char* title, int pages) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    strcpy(p->title, title);
    p->pages = pages;
    p->firstChild = NULL;
    p->nextSibling = NULL;
    return p;
}
/*THEM CON*/
void addChild(Node* parent, Node* child) {
    if (parent->firstChild == NULL)
        parent->firstChild = child;
    else {
        Node* temp = parent->firstChild;
        while (temp->nextSibling != NULL)
            temp = temp->nextSibling;
        temp->nextSibling = child;
    }
}
/*(1) DEM SO CHUONG*/
int countChapters(Node* root) {
    int count = 0;
    Node* temp = root->firstChild;
    while (temp != NULL) {
        count++;
        temp = temp->nextSibling;
    }
    return count;
}
/*(2) TIM CHUONG DAI NHAT*/
Node* longestChapter(Node* root) {
    Node* temp = root->firstChild;
    Node* maxChapter = NULL;
    int maxPages = -1;
    while (temp != NULL) {
        if (temp->pages > maxPages) {
            maxPages = temp->pages;
            maxChapter = temp;
        }
        temp = temp->nextSibling;
    }
    return maxChapter;
}
/*CAP NHAT SO TRANG*/
int updatePages(Node* t) {
    if (t == NULL) return 0;
    int sum = t->pages;
    Node* child = t->firstChild;
    while (child != NULL) {
        sum += updatePages(child);
        child = child->nextSibling;
    }
    t->pages = sum;
    return sum;
}
/*(3) XOA MOT MUC*/
int deleteNode(Node* parent, int id) {
    if (parent == NULL) return 0;
    Node* curr = parent->firstChild;
    Node* prev = NULL;
    while (curr != NULL) {
        if (curr->id == id) {
            if (prev == NULL)
                parent->firstChild = curr->nextSibling;
            else
                prev->nextSibling = curr->nextSibling;
            free(curr);
            updatePages(parent);
            return 1;
        }
        if (deleteNode(curr, id))
            return 1;
        prev = curr;
        curr = curr->nextSibling;
    }
    return 0;
}
/*(4) TIM CHUONG*/
Node* findChapter(Node* root, int id) {
    Node* temp = root->firstChild;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->nextSibling;
    }
    return NULL;
}
/*IN NOI DUNG CHUONG*/
void printChapter(Node* t, int level) {
    if (t == NULL) return;
    for (int i = 0; i < level; i++)
        printf("  ");
    printf("- %s (%d trang)\n", t->title, t->pages);
    Node* child = t->firstChild;
    while (child != NULL) {
        printChapter(child, level + 1);
        child = child->nextSibling;
    }
}
/*MAIN*/
int main() {
    Node* book = createNode(0, "BOOK", 0);
    Node* ch1 = createNode(1, "Chapter 1", 10);
    Node* ch2 = createNode(2, "Chapter 2", 15);
    addChild(book, ch1);
    addChild(book, ch2);
    addChild(ch1, createNode(11, "Section 1.1", 5));
    addChild(ch1, createNode(12, "Section 1.2", 3));
    addChild(ch2, createNode(21, "Section 2.1", 7));
    addChild(ch2, createNode(22, "Section 2.2", 4));
    printf("So chuong cua cuon sach: %d\n", countChapters(book));
    Node* maxCh = longestChapter(book);
    if (maxCh != NULL)
        printf("Chuong dai nhat: %s\n", maxCh->title);
    printf("\nXoa muc co ma muc la 12\n");
    deleteNode(book, 12);
    Node* c = findChapter(book, 1);
    printf("\nNoi dung Chapter 1:\n");
    printChapter(c, 0);
    return 0;
}
