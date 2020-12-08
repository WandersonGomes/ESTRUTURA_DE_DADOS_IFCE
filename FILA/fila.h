#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

Fila* criarFila();
void insereFila(Fila* fila, int valor);
int retiraFila(Fila* fila);
int vaziaFila(Fila* fila);
void imprimeFila(Fila* fila);
void liberaFila(Fila* fila);

#endif