#include "pilha.h"
#include <stdio.h>

int main() {
    Pilha* pilha = criaPilha();
    //PUSH
    push(pilha, 5);
    push(pilha, 4);
    push(pilha, 3);
    push(pilha, 2);
    push(pilha, 1);
    //POP
    printf("%.0f\n", pop(pilha));
    printf("%.0f\n", pop(pilha));
    printf("%.0f\n", pop(pilha));
    printf("%.0f\n", pop(pilha));
    printf("%.0f\n", pop(pilha));
    //IS EMPTY
    if (vazia(pilha)) {
        printf("Pilha vazia!\n");
    } else {
        printf("Pilha nao esta vazia.\n");
    }
    //CLEAR
    liberaPilha(pilha);
    return 0;
}