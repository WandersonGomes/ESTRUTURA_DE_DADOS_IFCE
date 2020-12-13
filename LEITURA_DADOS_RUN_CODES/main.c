#include "leitura.h"
#include <stdio.h>

int main() {
    char* string = readString(50);
    int i = 0, number_words = 0;

    number_words = countWords(string);

    printf("NUMBER WORDS: %d\n", number_words);

    printf("%d\n", stringToInteger("-10"));
    printf("%d\n", stringToInteger("+10"));
    printf("%d\n", stringToInteger("100"));
    
    for (; i < number_words; i++) {
        printf("WORD %d: %s\n", (i + 1), getWorldString(string, i+1, number_words));
    }


    clearString(string);
    return 0;
}