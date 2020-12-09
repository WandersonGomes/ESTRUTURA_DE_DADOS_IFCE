#ifndef PILHA_H
#define PILHA_H

typedef struct pilha Pilha;

Pilha* criarPilha();

void exibePilha(Pilha* pilha);
void esvaziarPilha(Pilha* pilha);
void pushPilha(Pilha* pilha, int valor);
int popPilha(Pilha* pilha);
int ultimo(Pilha* pilha);
int comprimento(Pilha* pilha);
int base(Pilha* pilha);
void destruirPilha(Pilha* pilha);

#endif