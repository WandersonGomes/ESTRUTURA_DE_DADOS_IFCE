#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fila.h"

#define TAM_OPCAO 3

int main() {
    int valor = 0;
    char opcao[TAM_OPCAO];
    Fila* fila = criarFila();

    while (1) {
        scanf("%s", opcao);

        if (strcmp(opcao, "-s") == 0) {
            exibeFila(fila);
            break;
        }

        if (strcmp(opcao, "-c") == 0) {
            esvaziaFila(fila);
        }

        if (strcmp(opcao, "-i") == 0) {
            scanf("%d", &valor);
            pushFila(fila, valor);
        }

        if (strcmp(opcao, "-r") == 0) {
            popFila(fila);
        }

        if (strcmp(opcao, "-sl") == 0) {
            printf("%d\n", ultimo(fila));
        }

        if (strcmp(opcao, "-sf") == 0) {
            printf("%d\n", primeiro(fila));
        }

        if (strcmp(opcao, "-ss") == 0) {
            printf("%d", comprimento(fila));
        }
    }

    destruirFila(fila);
    return 0;
}