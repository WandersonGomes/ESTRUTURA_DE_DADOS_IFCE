/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Necio de Lima Veras

Questao 02:
Crie um programa que aloca dinamicamente uma matriz de números
inteiros de dimensão MxN. O programa deve ver modularizado e ter
funções para alocar, ler, imprimir e deslocar a matriz.
*/
#include <stdio.h>
#include <stdlib.h>

//FUNCAO QUE ALOCA A MATRIZ MXN
int** alocaMatriz(int qtd_linhas, int qtd_colunas) {
    int i = 0;
    int** matriz = (int**) malloc(qtd_linhas * sizeof(int *));
    
    for (i = 0; i < qtd_linhas; i++) {
        matriz[i] = (int*) malloc(qtd_colunas * sizeof(int));
    }

    return matriz;
}

//FUNCAO QUE LIBERA A MEMORIA ALOCADA PARA A MATRIZ
void liberaMemoriaMatriz(int** matriz, int qtd_linhas) {
    int i = 0;
    
    for (i = 0; i < qtd_linhas; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

//FUNCAOQ QUE LER OS DADOS E ARMAZENA NA MATRIZ
void preencheMatriz(int** matriz, int qtd_linhas, int qtd_colunas) {
    int i = 0, j = 0;

    for (i = 0; i < qtd_linhas; i++) {
        for (j = 0; j < qtd_colunas; j++) {
            printf("Informe o dado da CELULA (%d, %d): ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

//FUNCAO QUE IMPRIME OS DADOS DA MATRIZ
void imprimeMatriz(int** matriz, int qtd_linhas, int qtd_colunas) {
    int i = 0, j = 0;

    printf("MATRIZ:\n");
    for (i = 0; i < qtd_linhas; i++) {
        for (j = 0; j < qtd_colunas; j++) {
            printf("%03d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//PROGRAMA PRINCIPAL
int main() {
    int numero_linhas = 0, numero_colunas = 0;
    int** matriz;

    do {
        printf("Informe a quantidade de linhas da matriz: ");
        scanf("%d", &numero_linhas);
        if (numero_linhas < 1) {
            printf("Error: quantidade invalida!\nTente novamente.\n");
        }
    } while (numero_linhas < 1);

    do {
        printf("Informe a quantidade de colunas da matriz: ");
        scanf("%d", &numero_colunas);
        if (numero_colunas < 1) {
            printf("Error: quantidade invalida!\nTente novamente.\n");
        }
    } while (numero_colunas < 1);

    matriz = alocaMatriz(numero_linhas, numero_colunas);
    
    preencheMatriz(matriz, numero_linhas, numero_colunas);

    imprimeMatriz(matriz, numero_linhas, numero_colunas);

    liberaMemoriaMatriz(matriz, numero_linhas);

    return 0;
}