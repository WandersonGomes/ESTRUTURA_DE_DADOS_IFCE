#include "leitura.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//AUXILIARY FUNCTIONS
int isCaracterValid(char caracter) {
    if ((caracter >= 'a') && (caracter <= 'z'))
        return 1;
    if ((caracter >= 'A') && (caracter <= 'Z'))
        return 1;
    if ((caracter >= '0') && (caracter <= '9'))
        return 1;
    if ((caracter == ' ') || (caracter == '!') || (caracter == '?'))
        return 1;
    if ((caracter == '.') || (caracter == ',') || (caracter == ';'))
        return 1;
    if ((caracter == '\'') || (caracter == '"'))
        return 1;
    if ((caracter == '(') || (caracter == ')'))
        return 1;
    if ((caracter == '+') || (caracter == '-'))
        return 1;
    if ((caracter == '#') || (caracter == '@'))
        return 1;
    return 0;
}

//MAIN FUNCTIONS
char* readString(int size) {
    char* tmp = (char*) malloc(sizeof(char) * (size+1));
    int i = 0;
    char caracter = 'a';

    while (1) {
        caracter = getchar();
        if (((caracter == '\n') && (i > 0)) || (i == size))
            break;
        else if (isCaracterValid(caracter)) {
            tmp[i] = caracter;
            i++;
        }
    }

    tmp[i] = '\0';

    return tmp;
}

int countWords(char* string) {
    int size = strlen(string);
    int i = 0, flag = 0, result = 0;
    
    if (size == 0)
        return -1;
    
    for (; i < size; i++) {
        if ((string[i] == ' ') && (flag)) {
            result++;
            flag = 0;
        } else if (isCaracterValid(string[i]) && (string[i] != ' ')) {
            flag = 1;
        }
    }

    if (flag)
        result++;
    
    return result;
}

int stringToInteger(char* string) {
    int size = 0, base = 1, i = 0, result = 0;

    size = strlen(string);
    for (i = size - 1; i >= 0; i--) {
        if ((string[i] != '+') && (string[i] != '-')) {
            result += (string[i]%48) * base;
            base *= 10;
        } else if (string[i] == '-') {
            result *= (-1);
        }
    }

    return result;
}

void clearString(char* string) {
    free(string);
}

char* getWorldString(char* string, int index, int count_words) {
    int i = 0, j = 0;
    int start = 0, end = 0, size = 0;
    char* word = NULL;


    if (index > count_words)
        return NULL;
    
    size = strlen(string);

    for (i = 0; i < index; i++) {
        while (string[j] == ' ')
            j++;
        start = j;
        while ((string[j] != ' ') && (j != size))
            j++;
        end = j-1;
    }

    word = (char*) malloc(sizeof(char) * ((end - start) + 1));

    j = 0;
    for (i = start; i <= end; i++) {
        word[j] = string[i];
        j++;
    }
    word[j] = '\0';
    
    return word;
}