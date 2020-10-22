/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Nécio de Lima Veras 
Descricao do problema:
Escreva um programa capaz de ler uma matriz de tamanho variável (leia: linha, depois coluna).
Depois de lida a dimensão da matriz, o algoritmo deve ler todos os elementos da matriz, um a um.
Ao final, o algoritmo deve exibir toda a matriz. 
*/
#include <stdio.h>
#include <stdlib.h>

int** geraMatriz(int linha, int coluna) {
    int** matriz = (int**) malloc(linha*sizeof(int*));
    int i = 0;

    for (i = 0; i < linha; i++) {
        matriz[i] = (int*) malloc(coluna*sizeof(int));
    }
    
    return matriz;
}

void libera(int** matriz, int linha) {
    int i = 0;
    for (i = 0; i < linha; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int **matriz = NULL;
    int linha = 0, coluna = 0, i = 0, j = 0;

    scanf("%d", &linha);
    scanf("%d", &coluna);

    matriz = geraMatriz(linha, coluna);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            if (j > 0) {
                printf(" %02d", matriz[i][j]);
            } else {
                printf("%02d", matriz[i][j]);
            }
        }
        printf("\n");
    }

    libera(matriz, linha);

    return 0;
}