#include "lista.h"

//STRUCT
struct reg {
    int conteudo;
    struct reg* prox;
};

//FUNCOES
void imprimeLista(Celula* lista) {
    if (lista != NULL) {
        printf("%d\n", lista->conteudo);
        imprimeLista(lista->prox);
    }
}

Celula* buscaLista(int conteudo, Celula* lista) {
    if (lista == NULL) return NULL;
    if (lista->conteudo == conteudo) return lista;
    return buscaLista(conteudo, lista->prox);
}

void insereLista(int conteudo, Celula* lista) {
    Celula* nova;
    nova = malloc(sizeof(Celula));
    nova->conteudo = conteudo;
    nova->prox = lista->prox;
    lista->prox = nova;
}

void removeLista(Celula* lista) {
    Celula* lixo;
    lixo = lista->prox;
    lista->prox = lixo->prox;
    free(lixo);
}

void buscaRemoveLista(int conteudo, Celula* lista) {
    Celula *auxiliar1, *auxiliar2;
    
    auxiliar1 = lista;
    auxiliar2 = lista->prox;

    while ((auxiliar2 != NULL) && (auxiliar2 != conteudo)) {
        auxiliar1 = auxiliar2;
        auxiliar2 = auxiliar2->prox;
    }

    if (auxiliar2 != NULL) {
        auxiliar1->prox = auxiliar2->prox;
        free(auxiliar2);
    }
}

void buscaInsereLista(int conteudo, int conteudo_procurado, Celula* lista) {
    Celula* auxiliar1, *auxiliar2, *nova;
    nova = malloc(sizeof(Celula));
    nova->conteudo = conteudo;

    auxiliar1 = lista;
    auxiliar2 = lista->prox;

    while ((auxiliar2 != NULL) && (auxiliar2->conteudo != conteudo_procurado)) {
        auxiliar1 = auxiliar2;
        auxiliar2 = auxiliar2->prox;
    }

    nova->prox = auxiliar2;
    auxiliar1->prox = nova;
}

void liberaLista(Celula* lista) {
    while (lista != NULL) {
        liberaLista(lista->prox);
        free(lista);
    }
}