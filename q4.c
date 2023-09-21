#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] >= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particao(arr, baixo, alto);

        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
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

    int totalElementos = linhas * colunas;
    int flatArray[totalElementos];
    int indice = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            flatArray[indice++] = mat[i][j];
        }
    }

    quicksort(flatArray, 0, totalElementos - 1);

    indice = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            mat[i][j] = flatArray[indice++];
        }
    }

    printf("\nMatriz ordenada:\n");
    imprimirMatriz(mat, linhas, colunas);

    return 0;
}