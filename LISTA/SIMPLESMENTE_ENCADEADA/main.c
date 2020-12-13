#include "lista.h"
#include <stdio.h>
#include <string.h>

int main() {
    List* list = createList();
    char option[4];
    int data = 0, index = 0;

    while (1) {
        scanf("%s", option);

        if (!strcmp(option, "-s")) {
            printList(list);
            break;
        }

        if (!strcmp(option, "-c"))
            emptyList(list);
        
        if (!strcmp(option, "-a")) {
            scanf("%d", &data);
            insertList(list, data);
        }

        if (!strcmp(option, "-ap")) {
            scanf("%d", &data);
            scanf("%d", &index);
            insertIndexList(list, data, index);
        }

        if (!strcmp(option, "-r")) {
            scanf("%d", &data);
            removeValueElementList(list, data);
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
            scanf("%d", &data);
            printf("%d\n", countLargerElementList(list, data));
        }
    }

    clearList(list);
    
    return 0;
}