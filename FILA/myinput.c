#include "myinput.h"
#include <stdio.h>
#include <string.h>

int isCaractereValid(char caracter) {
    if ((caracter >= 'a') && (caracter <= 'z'))
        return 1;
    if ((caracter >= 'A') && (caracter <= 'Z'))
        return 1;
    if ((caracter == ' ') || (caracter == '-') || (caracter == '\''))
        return 1;
    if ((caracter == '.') || (caracter == '!') || (caracter == '?'))
        return 1;
    if ((caracter >= '0') && (caracter <= '9'))
        return 1;
    return 0;
}

char* inputString(unsigned qtd_caracters) {
    qtd_caracters++;
    char* string = (char*) malloc(qtd_caracters * sizeof(char));
    char letter = 'a';
    int i = 0;

    while (1) {
        letter = getchar();
        if (((letter == '\n') && (i > 0)) || (i == (qtd_caracters - 1))) {
            break;
        } else if (isCaractereValid(letter)) {
            string[i] = letter;
            i++;
        }
    }

    string[i] = '\0';

    return string;
}