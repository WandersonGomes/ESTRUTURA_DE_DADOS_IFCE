/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Nécio de Lima Veras 
Descricao do problema:
Escreva um programa capaz de ler os elementos de um vetor 
de tamanho fixo (10 elementos) e mostre, ao final, o maior elemento.

Obs.: Eh um algoritmo ineficiente, porem eh o que deve ser utilizado
para demonstrar o uso do vetor.
*/
#include <stdio.h>

int main() {
    int vetor[10], posicao_maior = 0, i = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    for (i = 1; i < 10; i++) {
        if (vetor[i] > vetor[posicao_maior]) {
            posicao_maior = i;
        }
    }

    printf("%d\n", vetor[posicao_maior]);

    return 0;
}