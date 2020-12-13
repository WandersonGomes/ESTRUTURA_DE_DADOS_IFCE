#include "lista.h"
#include "leitura.h"
#include <stdio.h>
#include <string.h>

int main() {
    List* list = createList();
    int number_words = 0;
    char* input = NULL;
    char* option = NULL;
    char* data = NULL;
    char* index = NULL;

    while (1) {
        input = readString(15);

        number_words = countWords(input);

        option = getWorldString(input, 1, number_words);
        if (number_words > 1)
            data = getWorldString(input, 2, number_words);
        if (number_words > 2)
            index = getWorldString(input, 3, number_words);

        if (!strcmp(option, "-s")) {
            printList(list);
            break;
        }

        if (!strcmp(option, "-c"))
            emptyList(list);
        
        if (!strcmp(option, "-a")) {
            if (number_words == 2)
                insertList(list, stringToInteger(data));
            else
                insertIndexList(list, stringToInteger(data), stringToInteger(index));
        }

        if (!strcmp(option, "-ap")) {
            insertIndexList(list, stringToInteger(data), stringToInteger(index));
        }

        if (!strcmp(option, "-r")) {
            removeValueElementList(list, stringToInteger(data));
        }

        if (!strcmp(option, "-m")) 
            printf("%d\n", maxList(list));
        
        if (!strcmp(option, "-sl"))
            printf("%d\n", lastList(list));

        if (!strcmp(option, "-sf"))
            printf("%d\n", firsttList(list));
        
        if (!strcmp(option, "-ss"))
            printf("%d\n", sizeList(list));

        if (!strcmp(option, "-sg")) {
            printf("%d\n", countLargerElementList(list, stringToInteger(data)));
        }

        clearString(input);
    }

    clearList(list);
    
    return 0;
}