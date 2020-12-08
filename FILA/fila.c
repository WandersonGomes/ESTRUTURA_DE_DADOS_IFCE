#include "fila.h"
#include <stdlib.h>

typedef struct {
    int valor;
    struct no* proximo;
} No;

struct fila {
    No* inicio;
    No* fim;
};

Fila* criarFila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

/* funcao auxiliar: insere no fim */
No* ins_fim(No* fim, int valor) {
    No* auxiliar = (No*) malloc(sizeof(No));
    auxiliar->valor = valor;
    auxiliar->proximo = NULL;
    if (fim != NULL) 
        fim->proximo = auxiliar;
    return auxiliar;
}

/* funcao auxiliar: retira do inicio */
No* ret_ini(No* inicio) {
    No* auxiliar = inicio->proximo;
    free(inicio);
    return auxiliar;
}

void insereFila(Fila* fila, int valor) {
    fila->fim = ins_fim(fila->fim, valor);
    if (fila->inicio == NULL)
        fila->inicio = fila->fim;
}

int retiraFila(Fila* fila) {
    int valor = 0;
    if (vazia(fila)) {
        printf("Fila vazia.\n");
        exit(1);
    }
    valor = fila->inicio->valor;
    fila->inicio = ret_ini(fila->inicio);
    if (fila->inicio == NULL)
        fila->fim = NULL;
    return valor;
}

int vaziaFila(Fila* fila) {
    return (fila->inicio == NULL);
}

void liberaFila(Fila* fila) {
    No* auxiliar1 = fila->inicio;
    No* auxiliar2 = NULL;

    while (auxiliar1 != NULL) {
        No* auxiliar2 = auxiliar1->proximo;
        free(auxiliar1);
        auxiliar1 = auxiliar2;
    }

    free(fila);
}

void imprimeFila(Fila* fila) {
    No* auxiliar = fila->inicio;
    int flag = 1;

    if (vaziaFila(fila)) {
        printf("Fila vazia!");
    } else {
        while (auxiliar != NULL) {
            if (flag) {
                printf("%d", auxiliar->valor);
                fila = 0;
            } else {
                printf(", %d", auxiliar->valor);
            }
            auxiliar = auxiliar->proximo;
        }
    }
    printf("\n");
}