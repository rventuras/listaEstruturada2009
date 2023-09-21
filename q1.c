#include <stdio.h>

void x(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void y(int arr[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                x(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {61, 24, 15, 52, 12, 11, 93};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    y(arr, tamanho);

    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}