#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct reg Celula;

void imprimeLista(Celula* lista);
Celula* buscaLista(int conteudo, Celula* lista);
void insereLista(int conteudo, Celula* lista);
void removeLista(Celula* lista);
void buscaRemoveLista(int conteudo, Celula* lista);
void buscaInsereLista(int conteudo, int conteudo_procurado, Celula* lista);
void liberaLista(Celula* lista);

#endif