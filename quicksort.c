#include <stdio.h>
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void quickSort(int arr[], int dau, int cuoi, int n) {
    if (dau < cuoi) {
        int pivot = arr[cuoi];
        int i = (dau - 1);
        for (int j = dau; j < cuoi; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[cuoi];
        arr[cuoi] = temp;
        printf("Trạng thái mảng (quickSort): ");
        printArray(arr, n);
        int pi = i + 1;
        quickSort(arr, dau, pi - 1, n);
        quickSort(arr, pi + 1, cuoi, n);
    }
}
int main() {
    int arr[100], n;
    printf("Nhập số phần tử của mảng: ");
    scanf("%d", &n);
    printf("Nhập %d phần tử: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nSẮP XẾP NHANH (QUICK SORT)\n");
    quickSort(arr, 0, n - 1, n);
    printf("Kết quả cuối cùng: ");
    printArray(arr, n);
    printf("\n=== ĐỘ PHỨC TẠP THUẬT TOÁN ===\n");
    printf("Trung bình khi chia gần đều: O(n log n)\n");
    printf("Tốt nhất khi chia đều tất cả các bước:   O(n log n)\n");
    printf("Xấu nhất khi luôn lệch 0 | n-1:   O(n^2)\n");
    return 0;
}
