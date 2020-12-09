#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int valor = 0;
    char opcao[4];
    Pilha* pilha = criarPilha();

    while (1) {
        scanf("%s", opcao);

        if (strcmp(opcao, "-s") == 0) {
            exibePilha(pilha);
            break;
        }

        if (strcmp(opcao, "-c") == 0) {
            esvaziarPilha(pilha);
        }

        if (strcmp(opcao, "-i") == 0) {
            scanf("%d", &valor);
            pushPilha(pilha, valor);
        }

        if (strcmp(opcao, "-r") == 0) {
            popPilha(pilha);
        }

        if (strcmp(opcao, "-t") == 0) {
            printf("%d\n", ultimo(pilha));
        }

        if (strcmp(opcao, "-b") == 0) {
            printf("%d\n", base(pilha));
        }

        if (strcmp(opcao, "-ss") == 0) {
            printf("%d\n", comprimento(pilha));
        }
    }

    destruirPilha(pilha);
    
    return 0;
}