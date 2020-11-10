/*
Autor: Wanderson Gomes da Costa
Semestre: 2020.2
Disciplina: Estrutura de Dados
Professor: Necio de Lima Veras

Questao 01:
Faça uma função que receba como parâmetro um valor numérico e mostre a seguinte tabela de histogramas:
Elemento   Valor   Histograma
A          4           ∗∗∗∗
B          2           ∗∗
C          8           ∗∗∗∗∗∗∗∗
D          12         ∗∗∗∗∗∗∗∗∗∗∗∗
E          1           ∗

A quantidade de elementos deve ser lida no programa principal, bem como cada valor do histograma. 
A quantidade de elementos será o parâmetro para uma alocação dinâmica do histograma.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    char elemento;
    int quantidade;
    char *histograma;
} Elemento;


int main() {
    int quantidade_elementos = 0, i = 0, j = 0;
    Elemento* elementos = NULL;

    scanf("%d", &quantidade_elementos);

    elementos = (Elemento*) malloc(sizeof(Elemento) * quantidade_elementos);

    for (i = 0; i < quantidade_elementos; i++) {
        elementos[i].elemento = 65 + i;
        scanf("%d", &elementos[i].quantidade);

        elementos[i].histograma = (char*) malloc(sizeof(char) * (elementos[i].quantidade + 1));

        for (j = 0; j < elementos[i].quantidade; j++) {
            elementos[i].histograma[j] = '*';
        }

        elementos[i].histograma[j] = '\0';
    }

    for (i = 0; i < quantidade_elementos; i++) {
        printf("%c %d %s\n", elementos[i].elemento, elementos[i].quantidade, elementos[i].histograma);
    }

    for (i = 0; i < quantidade_elementos; i++) {
        free(elementos[i].histograma);
    }
    free(elementos);

    return 0;
}