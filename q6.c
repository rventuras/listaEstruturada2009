#include <stdio.h>

typedef struct {
    int linha;
    int coluna;
} Posicao;

void trocarPosicao(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Posicao buscarValor(int mat[][5], int linhas, int colunas, int valor) {
    Posicao posicao;
    posicao.linha = -1;
    posicao.coluna = -1;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (mat[i][j] == valor) {
                posicao.linha = i;
                posicao.coluna = j;
                return posicao;
            }
        }
    }

    return posicao;
}

int main() {
    int mat[][5] = {
        {64, 34, 25, 12, 22},
        {11, 90, 5, 9, 40},
        {55, 76, 8, 17, 13}
    };

    int linhas = sizeof(mat) / sizeof(mat[0]);
    int colunas = sizeof(mat[0]) / sizeof(mat[0][0]);

    int valorProcurado;
    printf("Digite o valor que deseja procurar: ");
    scanf("%d", &valorProcurado);

    Posicao posicao = buscarValor(mat, linhas, colunas, valorProcurado);

    if (posicao.linha != -1 && posicao.coluna != -1) {
        printf("Valor %d encontrado na posicao (%d, %d)\n", valorProcurado, posicao.linha, posicao.coluna);
    } else {
        printf("Valor %d nao encontrado na matriz.\n", valorProcurado);
    }

    return 0;
}