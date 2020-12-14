#include "lista.h"
#include <stdio.h>

int main() {
    List* list = createList();
    int i = 0, indice = 0;

    for (i = 0; i < 10; i++)
        insertStartList(list, i);
    for (i = 0; i < 10; i++)
        insertStartList(list, i);
    
    insertEndList(list, 19);

    while (indice > -1) {
        printf("Lista: ");
        printList(list);
        scanf("%d", &indice);
        printf("%d\n", countGreatValueList(list, 19));
    }

    destroyList(list);

    return 0;
}