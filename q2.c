#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quicksort(arr, left, j);
    if (i < right)
        quicksort(arr, i, right);
}

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergesort(arr, left, middle);
        mergesort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    srand(time(NULL));

    int sizes[] = {1000, 5000, 10000, 50000, 100000};

    for (int i = 0; i < sizeof(sizes) / sizeof(sizes[0]); i++) {
        int size = sizes[i];
        int *arr = (int *)malloc(sizeof(int) * size);

        for (int j = 0; j < size; j++) {
            arr[j] = rand();
        }

        clock_t start, end;

        int *arrBubble = (int *)malloc(sizeof(int) * size);
        memcpy(arrBubble, arr, sizeof(int) * size);
        start = clock();
        bubbleSort(arrBubble, size);
        end = clock();
        printf("Tempo de execucao (BubbleSort) para tamanho %d: %f segundos\n", size, (double)(end - start) / CLOCKS_PER_SEC);
        free(arrBubble);

        int *arrQuick = (int *)malloc(sizeof(int) * size);
        memcpy(arrQuick, arr, sizeof(int) * size);
        start = clock();
        quicksort(arrQuick, 0, size - 1);
        end = clock();
        printf("Tempo de execucao (Quicksort) para tamanho %d: %f segundos\n", size, (double)(end - start) / CLOCKS_PER_SEC);
        free(arrQuick);

        int *arrMerge = (int *)malloc(sizeof(int) * size);
        memcpy(arrMerge, arr, sizeof(int) * size);
        start = clock();
        mergesort(arrMerge, 0, size - 1);
        end = clock();
        printf("Tempo de execucao (Mergesort) para tamanho %d: %f segundos\n", size, (double)(end - start) / CLOCKS_PER_SEC);
        free(arrMerge);

        free(arr);
    }

    return 0;
}