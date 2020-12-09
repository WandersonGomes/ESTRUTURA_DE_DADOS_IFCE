#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

Fila* criarFila();
void exibeFila(Fila* fila);
void esvaziaFila(Fila* fila);
void pushFila(Fila* fila, int valor);
int popFila(Fila* fila);
int ultimo(Fila* fila);
int primeiro(Fila* fila);
int comprimento(Fila* fila);
void destruirFila(Fila* fila);

#endif