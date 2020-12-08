#ifndef PILHA_H
#define PILHA_H

typedef struct no DataNo;
typedef struct pilha Pilha;

Pilha* criaPilha();
void push(Pilha* pilha, float valor);
float pop(Pilha* pilha);
int vazia(Pilha* pilha);
void liberaPilha(Pilha* pilha);
void imprime(Pilha *pilha);

#endif