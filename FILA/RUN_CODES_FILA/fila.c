#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct no {
    int valor;
    struct no* proximo;
} No;

struct fila {
    int qtd_elementos;
    No* inicio;
    No* fim;
};


Fila* criarFila() {
    Fila* temp = (Fila*) malloc(sizeof(Fila));
    return temp;
}

void exibeFila(Fila* fila) {
    No* temp = NULL;
    int flag = 1;

    if (fila != NULL) {
        if (fila->qtd_elementos == 0) {
            printf("Fila vazia\n");
        } else {
            temp = fila->inicio;
            while (temp != NULL) {
                if (flag) {
                    printf("%d", temp->valor);
                    flag = 0;
                } else {
                    printf(", %d", temp->valor);
                }
                temp = temp->proximo;
            }
            printf("\n");
        }
    } else {
        printf("Error: Fila nao definida!\n");
    }
}

void esvaziaFila(Fila* fila) {
    No* temp1 = NULL;
    No* temp2 = NULL;

    if (fila != NULL) {
        fila->qtd_elementos = 0;
        
        temp1 = fila->inicio;
        while (temp1 != NULL) {
            temp2 = temp1->proximo;
            free(temp1);
            temp1 = temp2;
        }

        fila->inicio = NULL;
        fila->fim = NULL;
    } else {
        printf("Error: fila nao definida!\n");
    }
    
}

void pushFila(Fila* fila, int valor) {
    No* temp = NULL;
    if (fila != NULL) {
        temp = (No*) malloc(sizeof(No));
        temp->valor = valor;
        temp->proximo = NULL;
        
        if (fila->qtd_elementos == 0) {
            fila->inicio = temp;
            fila->fim = temp;
        } else {
            fila->fim->proximo = temp;
            fila->fim = temp;
        }

        fila->qtd_elementos++;
    } else {
        printf("Error: fila nao definida!\n");
    }
}

int popFila(Fila* fila) {
    No* temp = NULL;
    int resultado = 0;

    if (fila != NULL) {
        temp = fila->inicio;

        if (fila->qtd_elementos >= 1) {
            resultado = temp->valor;
            fila->inicio = fila->inicio->proximo;
            
            if (fila->qtd_elementos == 1)
                fila->fim = NULL;
            
            free(temp);
            fila->qtd_elementos--;
        } else {
            return INT_MIN;
        }

        return resultado;
    } else {
        printf("Error: fila nao definida!\n");
    }
    return INT_MIN;
}

int ultimo(Fila* fila) {
    if (fila != NULL) {
        if (fila->qtd_elementos >= 1) {
            return fila->fim->valor;
        }
    } else {
        printf("Error: fila nao definida!\n");
    }
    return INT_MIN;
}

int primeiro(Fila* fila) {
    if (fila != NULL) {
        if (fila->qtd_elementos >= 1) {
            return fila->inicio->valor;
        }
    } else {
        printf("Error: fila nao definida!\n");
    }
    return INT_MIN;
}

int comprimento(Fila* fila) {
    if (fila != NULL) {
        return fila->qtd_elementos;
    } else {
        printf("Error: fila nao definida!\n");
    }
    return INT_MIN;
}

void destruirFila(Fila* fila) {
    esvaziaFila(fila);
    free(fila);
}