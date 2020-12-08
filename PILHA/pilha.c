#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    float valor;
    struct no* proximo;
} No;

struct pilha {
    No* topo;
};

Pilha* criaPilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

/* funcao auxiliar: insere no inicio */
No* ins_ini (No* l, float v) {
    No* p = (No*) malloc(sizeof(No));
    p->valor = v;
    p->proximo = l;
    return p;
}

/* funcao auxiliar: retira do inicio */
No* ret_ini(No* l) {
    No* p = l->proximo;
    free(l);
    return p;
}

void push(Pilha* pilha, float valor) {
    pilha->topo = ins_ini(pilha->topo, valor);
}

float pop(Pilha* pilha) {
    float valor = 0.0;
    if (vazia(pilha)) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    valor = pilha->topo->valor;
    pilha->topo = ret_ini(pilha->topo);
    return valor;
}

int vazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void liberaPilha(Pilha* pilha) {
    No* auxiliar1 = pilha->topo;
    No* auxiliar2 = NULL;
    
    while (auxiliar1 != NULL) {
        auxiliar2 = auxiliar1->proximo;
        free(auxiliar1);
        auxiliar1 = auxiliar2;
    }
    
    free(pilha);
}

void imprimePilha(Pilha* pilha) {
    No* auxiliar;
    for (auxiliar = pilha->topo; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        printf("%g\n", auxiliar->valor);
    }
}