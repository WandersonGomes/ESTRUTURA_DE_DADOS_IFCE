#include "list.h"
#include <stdio.h>

#define MIN -1
#define MAX 22

//MENU
void printMenu() {
    printf("\n\n---MENU---\n");
    printf("00 - INSERIR VALOR NO INICIO DA LISTA.\n");
    printf("01 - INSERIR VALOR NO FINAL DA LISTA.\n");
    printf("02 - INSERIR VALOR DE FORMA ORDENADA.\n");
    printf("03 - INSERIR VALOR EM UM INDICE ESPECIFICO.\n");

    printf("04 - VERIFICAR SE A LISTA ESTA VAZIA.\n");
    printf("05 - APRESENTAR O PRIMEIRO ELEMENTO DA LISTA.\n");
    printf("06 - APRESENTAR O ULTIMO ELEMENTO DA LISTA.\n");
    printf("07 - APRESENTAR O ELEMENTO EM UM INDICE INFORMADO.\n");
    printf("08 - APRESENTAR O TAMANHO DA LISTA.\n");

    printf("09 - REMOVER ELEMENTO DO INICIO DA LISTA.\n");
    printf("10 - REMOVER ELEMENTO DO FINAL DA LISTA.\n");
    printf("11 - REMOVER VALOR (APENAS UM) DA LISTA.\n");
    printf("12 - REMOVER VALOR (TODOS) DA LISTA.\n");
    printf("13 - REMOVER VALOR DE UM INDICE DA LISTA.\n");

    printf("14 - RETIRAR TODOS OS ELEMENTOS DA LISTA.\n");
    printf("15 - IMPRIMIR A LISTA.\n");
    
    printf("16 - MAIOR VALOR NA LISTA.\n");
    printf("17 - MENOR VALOR DA LISTA\n");
    printf("18 - QUANTIDADE DE NUMEROS MAIORES QUE UM VALOR.\n");

    printf("19 - MERGER DUAS LISTAS.\n");
    printf("20 - INVERTER LISTA.\n");
    printf("21 - CONVERTER LISTA PARA CIRCULAR.\n");
    printf("22 - REVERTENDO LISTA CIRCULAR DE FORMA RECURSIVA.\n");

    printf("-1 - ENCERRAR PROGRAMA.\n");
}

//PREENCHER UMA LISTA
void preencherLista(List* list) {
    int qtd_items = 0, i = 0, valor = 0;
    do {
        printf("Informe a quantidade de itens da lista: ");
        scanf("%d", &qtd_items);
        if (qtd_items <= 0)
            printf("Error: valor invalido!\nTente novamente.\n");
    } while (qtd_items <= 0);

    for (i = 0; i < qtd_items; i++) {
        printf("Informe o %d.o item: ", i+1);
        scanf("%d", &valor);
        insertEndList(list, valor);
    }
}

//PROGRAMA PRINCIPAL
int main() {
    List* list_merge = NULL;
    List* list1 = NULL;
    List* list2 = NULL;

    List* list = createList();
    int opcao = 0, valor = 0, indice = 0;

    while (opcao != -1) {
        do {
            printMenu();
            printf("Opcao: ");
            scanf("%d", &opcao);
            if ((opcao < MIN) || (opcao > MAX))
                printf("\nError: valor invalido!\nTente novamente.\n");
        } while ((opcao < MIN) || opcao > MAX);

        switch(opcao) {
            case -1:
                break;
            case 0: 
                printf("Informe o valor: ");
                scanf("%d", &valor);
                insertStartList(list, valor);
                printf("Lista: ");
                printList(list);
                printf("\n");
                break;
            case 1: 
                printf("Informe o valor: ");
                scanf("%d", &valor);
                insertEndList(list, valor);
                printf("Lista: ");
                printList(list);
                printf("\n");
                break;
            case 2:
                printf("Informe o valor: ");
                scanf("%d", &valor);
                insertSortList(list, valor);
                printf("Lista: ");
                printList(list);
                printf("\n");
                break;
            case 3:
                printf("Informe o valor: ");
                scanf("%d", &valor);
                printf("Informe o indice: ");
                scanf("%d", &indice);
                insertIndexList(list, indice, valor);
                printf("Lista: "); printList(list); printf("\n");
                break;
            case 4:
                if (isEmptyList(list))
                    printf("Lista vazia!\n");
                else
                    printf("Lista nao esta vazia!\n");
                break;
            case 5:
                printf("Primeiro elemento da lista: %d\n", startList(list));
                break;
            case 6:
                printf("Ultimo elemento da lista: %d\n", endList(list));
                break;
            case 7:
                printf("Informe o indice escolhido: ");
                scanf("%d", &indice);
                printf("Valor encontrado: %d\n", dataIndexList(list, indice));
                break;
            case 8:
                printf("Tamanho da lista: %d\n", sizeList(list));
                break;
            case 9:
                printf("Valor %d removido.\n", startList(list));
                removeStartList(list);
                printf("Lista: "); printList(list); printf("\n");
                break;
            case 10:
                printf("Elemento %d removido.\n", endList(list));
                removeEndList(list);
                printf("Lista: "); printList(list); printf("\n");
                break;
            case 11:
                printf("Informe o valor a ser removido: ");
                scanf("%d", &valor);
                removeDataList(list, valor);
                printf("Lista: "); printList(list); printf("\n");
                break;
            case 12:
                printf("Informe o valor a ser removido: ");
                scanf("%d", &valor);
                removeAllDataList(list, valor);
                printf("Lista: "); printList(list); printf("\n");
                break;
            case 13:
                printf("Informe o indice do valor a ser removido: ");
                scanf("%d", &indice);
                removeDataIndexList(list, indice);
                printf("Lista: "); printList(list); printf("\n");
                break;
            case 14:
                clearList(list);
                printf("Lista: "); printList(list); printf("\n");
                break;
            case 15:
                printf("Lista: "); printList(list); printf("\n");
                break;
            case 16:
                printf("Maior valor da lista: %d\n", maxDataList(list));
                break;
            case 17:
                printf("Menor valor da lista: %d\n", minDataList(list));
                break;
            case 18:
                printf("Informe o valor: ");
                scanf("%d", &valor);
                printf("Quantidade de numeros maiores que %d: %d\n", valor, countLargerDataList(list, valor));
                break;
            case 19:
                list1 = createList();
                list2 = createList();
                printf("Preencha a primeira lista.\n");
                preencherLista(list1);
                printf("\nPreencha a segunda lista.\n");
                preencherLista(list2);
                list_merge = mergeList(list1, list2);
                printf("Lista: "); printList(list_merge); printf("\n");
                break;
            case 20:
                printf("Invertendo lista...\n");
                reverseList(list);
                printf("Lista: "); printList(list); printf("\n"); 
                break;
            case 21:
                printf("Convertendo para circular...\n");
                if (convertListToCircular(list))
                    printf("Convertida com sucesso!\n");
                else
                    printf("Nao foi convertida!\n");
                break;
            case 22:
                printf("Revertendo lista circultar de forma recursiva...\n");
                reverseListCircularRecursive(list);
                printf("Lista: "); printList(list); printf("\n");
                break;
        }
    }

    destroyList(list);
    return 0;
}