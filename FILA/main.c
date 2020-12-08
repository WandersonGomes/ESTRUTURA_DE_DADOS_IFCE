#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

//FUNCAO QUE CHECA SE UM DADO E LETRA
int ehLetra(char caractere) {
    if ((caractere >= 'A') && (caractere <= 'Z'))
        return 1;
    if ((caractere >= 'a') && (caractere <= 'z'))
        return 1;
    if ((caractere == '-') || (caractere == '+') || (caractere == ' '))
        return 1;
    if ((caractere >= '0') && (caractere <= '9'))
        return 1;
    return 0;
}

//FUNCAO QUE LER UMA STRING
char* lerString(int quantidade_caracteres) {
    char* string = (char*) malloc(sizeof(char) * quantidade_caracteres);
    char letra = 'a';
    int i = 0;

    while (1) {
        letra = getchar();
        if (((letra == '\n') && (i > 0)) || (i == (quantidade_caracteres - 1))) {
            break;
        } else if (ehLetra(letra)) {
            string[i] = letra;
            i++;
        }
    }

    string[i] = '\0';

    return string;
}

//PROGRAMA PRINCIPAL
int main() {
    int valor = 0;
    char* opcao;
    Fila* fila = criarFila();
    
    while (1) {
        opcao = lerString(4);

        if (strcmp(opcao, "-s") == 0) {
            imprimeFila(fila);
        }
        if (strcmp(opcao, "-c") == 0) {
            while(!vaziaFila(fila)) {
                retiraFila(fila);
            }
        }
        if (strcmp(opcao, "-i") == 0) {
            scanf("%d", &valor);
            insereFila(fila, valor);
        }
        if (strcmp(opcao, "-r") == 0) {
            retiraFila(fila);
        }
        if (strcmp(opcao, "-sl") == 0) {
            printf("%d\n", ultimoElementoFila(fila));
        }
        if (strcmp(opcao, "-sf") == 0) {
            printf("%d\n", primeiroElementoFila(fila));
        }
        if (strcmp(opcao, "-ss") == 0) {
            printf("%d\n", tamanhoFila(fila));
        }
    }

    return 1;
}