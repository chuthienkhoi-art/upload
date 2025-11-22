#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hoten[50];
    char mssv[15];
    int namsinh;
    float gpa;
} SinhVien;

typedef struct Node {
    SinhVien data;
    struct Node *next;
} Node;

Node* taoNode(SinhVien sv) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = sv;
    p->next = NULL;
    return p;
}

void themCuoi(Node **dau, SinhVien sv) {
    Node *p = taoNode(sv);
    if (*dau == NULL) {
        *dau = p;
        return;
    }
    Node *tmp = *dau;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = p;
}

void inDanhSach(Node *dau) {
    int i = 1;
    while (dau != NULL) {
        printf("%d. %s | %s | %d | %.2f\n",
               i, dau->data.hoten, dau->data.mssv,
               dau->data.namsinh, dau->data.gpa);
        dau = dau->next;
        i++;
    }
}

int chieuDai(Node *dau) {
    int count = 0;
    while (dau != NULL) {
        count++;
        dau = dau->next;
    }
    return count;
}

int demGPAHon32(Node *dau) {
    int count = 0;
    while (dau != NULL) {
        if (dau->data.gpa > 3.2)
            count++;
        dau = dau->next;
    }
    return count;
}

void sapXep(Node *dau) {
    for (Node *i = dau; i != NULL; i = i->next)
        for (Node *j = i->next; j != NULL; j = j->next)
            if (i->data.gpa > j->data.gpa) {
                SinhVien t = i->data;
                i->data = j->data;
                j->data = t;
            }
}

void chenCoThuTu(Node **dau, SinhVien sv) {
    Node *p = taoNode(sv);
    if (*dau == NULL || (*dau)->data.gpa > sv.gpa) {
        p->next = *dau;
        *dau = p;
        return;
    }
    Node *tmp = *dau;
    while (tmp->next != NULL && tmp->next->data.gpa < sv.gpa)
        tmp = tmp->next;
    p->next = tmp->next;
    tmp->next = p;
}

int main() {
    Node *dau = NULL;
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        SinhVien sv;
        printf("\nNhap sinh vien %d:\n", i + 1);

        printf("Ho ten: ");
        fgets(sv.hoten, sizeof(sv.hoten), stdin);
        sv.hoten[strcspn(sv.hoten, "\n")] = 0;

        printf("MSSV: ");
        fgets(sv.mssv, sizeof(sv.mssv), stdin);
        sv.mssv[strcspn(sv.mssv, "\n")] = 0;

        printf("Nam sinh: ");
        scanf("%d", &sv.namsinh);

        printf("GPA: ");
        scanf("%f", &sv.gpa);
        getchar();

        themCuoi(&dau, sv);
    }

    printf("\n--- Danh sach vua nhap ---\n");
    inDanhSach(dau);

    printf("\nChieu dai danh sach: %d", chieuDai(dau));
    printf("\nSo sinh vien GPA > 3.2: %d\n", demGPAHon32(dau));

    sapXep(dau);
    printf("\n--- Sau sap xep GPA tang dan ---\n");
    inDanhSach(dau);

    SinhVien svMoi = {"Sinh Vien Moi", "SV100", 2004, 2.4};
    chenCoThuTu(&dau, svMoi);

    printf("\n--- Sau khi chen SV GPA = 2.4 ---\n");
    inDanhSach(dau);

    return 0;
}
