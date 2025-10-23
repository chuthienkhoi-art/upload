#include <stdio.h>
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void bubbleSort(int a[], int n) {
    printf("\n=== BUBBLE SORT ===\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("Bước %d: ", i + 1);
        printArray(a, n);
    }
}
void selectionSort(int a[], int n) {
    printf("\n=== SELECTION SORT ===\n");
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
        printf("Bước %d: ", i + 1);
        printArray(a, n);
    }
}
void insertionSort(int a[], int n) {
    printf("\n=== INSERTION SORT ===\n");
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        printf("Bước %d: ", i);
        printArray(a, n);
    }
}
int main() {
    int n;
    printf("Nhập số phần tử: ");
    scanf("%d", &n);

    int arr1[n], arr2[n], arr3[n];
    printf("Nhập %d phần tử: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    bubbleSort(arr1, n);
    selectionSort(arr2, n);
    insertionSort(arr3, n);

    return 0;
}