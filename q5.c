#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenacaoInsercao(int arr[], int tamanho) {
    int i, j, chave;
    for (i = 0; i < tamanho; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

void ordenarMatriz(int mat[][5], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        ordenacaoInsercao(mat[i], colunas);
    }
}

void imprimirMatriz(int mat[][5], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat[][5] = {
        {64, 34, 25, 12, 22},
        {11, 90, 5, 9, 40},
        {55, 76, 8, 17, 13}
    };

    int linhas = sizeof(mat) / sizeof(mat[0]);
    int colunas = sizeof(mat[0]) / sizeof(mat[0][0]);

    printf("Matriz original:\n");
    imprimirMatriz(mat, linhas, colunas);

    ordenarMatriz(mat, linhas, colunas);

    printf("\nMatriz ordenada:\n");
    imprimirMatriz(mat, linhas, colunas);

    return 0;
}