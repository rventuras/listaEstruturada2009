#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarDecrescente(int arr[], int tamanho) {
    int i, j, chave;
    for (i = 1; i < tamanho; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < chave) {
            trocar(&arr[j + 1], &arr[j]);
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int arr[] = {2, 13, 13, 1, 15};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    ordenarDecrescente(arr, tamanho);

    printf("\nArray ordenado em ordem decrescente: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}