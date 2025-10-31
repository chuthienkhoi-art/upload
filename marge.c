#include <stdio.h>
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void merge(int arr[], int h, int m, int p, int n) {
    int n1 = m - h + 1;
    int n2 = p - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[h + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = h;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    printf("Trạng thái mảng (mergeSort): ");
    printArray(arr, n);
}
void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);
        merge(arr, l, m, r, n);
    }
}
int main() {
    int arr[100], n;
    printf("Nhập số phần tử của mảng: ");
    scanf("%d", &n);
    printf("Nhập %d phần tử: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nSẮP XẾP TRỘN (MERGE SORT)\n");
    mergeSort(arr, 0, n - 1, n);
    printf("Kết quả cuối cùng: ");
    printArray(arr, n);
    printf("\nĐỘ PHỨC TẠP THUẬT TOÁN\n");
    printf("O(n log n)\n");
    return 0;
}

