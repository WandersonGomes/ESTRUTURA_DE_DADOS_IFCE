#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct no {
    int valor;
    struct no* proximo;
} No;

struct pilha {
    int qtd_elementos;
    No* topo;
    No* base;
};

Pilha* criarPilha() {
    Pilha* temp = (Pilha*) malloc(sizeof(Pilha));
    temp->qtd_elementos = 0;
    temp->topo = NULL;
    temp->base = NULL;
    return temp;
}

void exibePilha(Pilha* pilha) {
    No* topo = NULL;
    int flag = 1;

    if (pilha != NULL) {
        if (pilha->qtd_elementos > 0) {
            topo = pilha->topo;
            
            while (topo != NULL) {
                if (flag) {
                    printf("%d", topo->valor);
                    flag = 0;
                } else {
                    printf(", %d", topo->valor);
                }

                topo = topo->proximo;
            }
            printf("\n");
        } else {
            printf("Pilha vazia\n");
        }
    } else {
        printf("Error: pilha nao definida!\n");
    }
}

void esvaziarPilha(Pilha* pilha) {
    No* aux1 = NULL;
    No* aux2 = NULL;

    if (pilha != NULL) {
        aux1 = pilha->topo;
        
        while (aux1 != NULL) {
            aux2 = aux1->proximo;
            free(aux1);
            aux1 = aux2;
        }

        pilha->topo = NULL;
        pilha->base = NULL;
        pilha->qtd_elementos = 0;
    } else {
        printf("Error: pilha nao definida!\n");
    }
}

void pushPilha(Pilha* pilha, int valor) {
    if (pilha != NULL) {
        No* temp = (No*) malloc(sizeof(No));
        temp->valor = valor;
        temp->proximo = pilha->topo;
        pilha->topo = temp;
        if (pilha->qtd_elementos == 0)
            pilha->base = temp;
        pilha->qtd_elementos++;
    } else {
        printf("Error: pilha nao definida!\n");
    }
}

int popPilha(Pilha* pilha) {
    No* temp = NULL;
    int resultado = 0;

    if (pilha != NULL) {
        if (pilha->qtd_elementos > 0) {
            temp = pilha->topo;
            pilha->topo = pilha->topo->proximo;
            resultado = temp->valor;
            free(temp);
            pilha->qtd_elementos--;

            if (pilha->qtd_elementos == 0)
                pilha->base = NULL;
            
            return resultado;
        } else {
            printf("Error: pilha vazia\n");
            return INT_MIN;
        }
    } else {
        printf("Error: pilha nao definida!\n");
        return INT_MIN;
    }
}

int ultimo(Pilha* pilha) {
    if (pilha != NULL) {
        if (pilha->qtd_elementos > 0) {
            return pilha->topo->valor;
        }
    } else {
        printf("Error: pilha nao definida!\n");
    }
    return INT_MIN;
}

int comprimento(Pilha* pilha) {
    if (pilha != NULL) {
        return pilha->qtd_elementos;
    } else {
        printf("Error: pilha nao definida!\n");        
    }
    return INT_MIN;
}

int base(Pilha* pilha) {
    if (pilha != NULL) {
        if (pilha->qtd_elementos > 0)
            return pilha->base->valor;
    }
    return INT_MIN;
}

void destruirPilha(Pilha* pilha) {
    if (pilha != NULL) {
        esvaziarPilha(pilha);
        free(pilha);
    } else {
        printf("Error: pilha nao definida!\n");
    }
}