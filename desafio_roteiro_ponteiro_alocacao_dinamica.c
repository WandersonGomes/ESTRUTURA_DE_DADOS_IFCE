/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Necio de Lima Veras

Desafio:
Escreva funções para lidar com matrizes triangulares inferiores de
dimensão n × n, onde todos os elementos abaixo da diagonal são iguais a
zero e não devem ser alocados. No entanto, um acesso a um elemento
abaixo da diagonal deve retornar o valor zero. Escreva as seguintes
funções, usando a estratégia de vetor de ponteiros para armazenar a matriz.

(a) Função para criar uma matriz, onde n representa a dimensão da matriz,
inicialmente com os valores todos iguais a zero:
float **cria(int n);

(b) Função para atribuir o valor de um elemento da matriz, assumindo que
i < = j:
void atribui(int i, int j, float x, float **mat);

(c) Função para acessar o valor de um elemento da matriz, inclusive
elementos abaixo da diagonal:
float acessa(int i, int j, float **mat);

(d) Função para liberar a memória da matriz alocada:
void libera(int n, float **mat);

Escreva uma função main para testar as funções implementadas.
*/
#include <stdio.h>
#include <stdlib.h>

//FUNCAO QUE CRIA A MATRIZ TRIANGULAR
float** criaMatrizTriangular(int dimensao) {
    int i = 0;
    float** matriz = (float**) malloc(sizeof(float*) * dimensao);

    for (i = 0; i < dimensao; i++) {
        matriz[i] = (float*) calloc((dimensao-i), sizeof(float));
    }

    return matriz;
}

//FUNCAO QUE ATRIBUI UM VALOR DE UM ELEMENTO DA MATRIZ
void atribui(int i, int j, float valor, float** matriz) {
    matriz[i][j] = valor;
}

//FUNCAO PARA ACESSAR O VALOR DA MATRIZ TRIANGULAR
float acessa(int i, int j, float** matriz) {
    if (i > j) {
        return 0.0;
    } else {
        return matriz[i][j];
    }
}

//FUNCAO PARA LIBERAR A MEMORIA UTILIZADA
void liberaMemoriaMatriz(int dimensao, float** matriz) {
    int i = 0;

    for (i = 0; i < dimensao; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

//PROGRAMA PRINCIPAL
int main() {
    int dimensao = 0, linha = 0, coluna = 0;
    float** matriz = NULL;
    float valor = 0.0;
    int i = 0, j = 0;

    //ler a dimensao da matriz
    do {
        printf("Informe a dimensao da matriz triangular: ");
        scanf("%d", &dimensao);
        if (dimensao < 1) {
            printf("Error: dimensao invalida!\nTente novamente.\n");
        }
    } while (dimensao < 1);

    //aloca e cria a matriz
    matriz = criaMatrizTriangular(dimensao);

    //insere os dados na matriz
    printf("\nLembre-se que a linha tem que ser menor ou igual a coluna!\n");
    while (1) {
        do {
            printf("Informe a linha que deseja inserir o dado ou 0 para encerrar: ");
            scanf("%d", &linha);
            if (linha < 0 || linha > dimensao) {
                printf("Error: linha incorreta!\nTente novamente.\n");
            }
        } while (linha < 0 || linha > dimensao);

        //encerra a insercao
        if (linha == 0) {
            break;
        }

        do {
            printf("Informe a coluna que deseja inserir o dado: ");
            scanf("%d", &coluna);
            if (coluna < linha || coluna > dimensao) {
                printf("Error: coluna incorreta!\nTente novamente.\n");
            }
        } while (coluna < linha || coluna > dimensao);

        printf("Informe o valor que deseja inserir: ");
        scanf("%f", &valor);

        atribui(linha-1, coluna-1, valor, matriz);
    }

    //imprime a matriz
    printf("\nMATRIZ:\n");
    for (i = 0; i < dimensao; i++) {
        for (j = 0; j < dimensao; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    //libera a memoria
    liberaMemoriaMatriz(dimensao, matriz);

    return 0;
}