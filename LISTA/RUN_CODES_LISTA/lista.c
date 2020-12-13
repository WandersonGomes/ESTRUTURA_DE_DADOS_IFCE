#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct node {
    int info;
    struct node* next;
} Node;


struct list {
    int size;
    Node* first;
    Node* last;
};

List* createList() {
    List* tmp = (List*) malloc(sizeof(List));
    
    if (tmp == NULL) {
        printf("Error: createList()\n");
        return NULL;
    }

    tmp->size = 0;
    tmp->first = NULL;
    tmp->last = NULL;

    return tmp;
}

int isEmptyList(List* list) {
    if (list == NULL)
        return -1;
    
    return (list->size == 0);
}

int insertList(List* list, int data) {
    Node* tmp = NULL;

    if (list != NULL) {
        tmp = (Node*) malloc(sizeof(Node));    
        tmp->info = data;
        tmp->next = list->first;
        list->first = tmp;
        
        if (isEmptyList(list))
            list->last = tmp;
        
        list->size++;

        return 1;
    } else {
        printf("Error: insertList()\n");
        return 0;
    }
}

int insertSortList(List* list, int data) {
    Node* tmp = NULL;
    Node* current = NULL;
    Node* previous = NULL;

    if (list != NULL) {
        tmp = (Node*) malloc(sizeof(Node));
        tmp->info = data;
        tmp->next = NULL;
        
        //lista vazia
        if (isEmptyList(list)) {
            list->first = tmp;
            list->last = tmp;
        } else {
            current = list->first;

            //primeiro maior que o valor inserido
            if (data < current->info) {
                tmp->next = list->first;
                list->first = tmp;
            } else {
                while ((current != NULL) && (current->info <= data)) {
                    previous = current;
                    current = current->next;
                }

                //final da lista
                if (current == NULL)
                    list->last = tmp;
                
                tmp->next = current;
                previous->next = tmp;
            }
        }

        list->size++;
        return 1;
    } else {
        printf("Error: insertSortList()\n");
        return 0;
    }
}

int insertIndexList(List* list, int data, int index) {
    index--;
    int i = 0, size = 0;
    Node* current = NULL;
    Node* new = NULL;

    if (list == NULL)
        return -1;

    size = sizeList(list);

    if (index > size)
        return 0;
    

    //primeira posicao
    if (index == 0) {
        insertList(list, data);
        return 1;
    }

    new = (Node*) malloc(sizeof(Node));
    new->info = data;
    new->next = NULL;

    //ultima posicao
    if (index == sizeList(list)) {
        list->last->next = new;
        list->last = new;
        list->size++;
        return 1;
    }

    //pelo meio
    current = list->first;
    while (i < index - 1) {
        current = current->next;
        i++;
    }

    new->next = current->next;
    current->next = new;
    list->size++;

    return 1;
}

int removeIndexElementoList(List* list, int index) {

}

int getIndexElement(List* list, int index) {

}

int removeValueElementList(List* list, int data) {
    Node* current = NULL;
    Node* previous = NULL;

    if (list != NULL) {
        current = list->first;
        while (1) {
            if (current == NULL)
                break;
            
            //lista so tem um item
            if ((sizeList(list) == 1) && (current->info == data)) {
                list->first = NULL;
                list->last = NULL;
                list->size = 0;
                free(current);
                break;
            }

            //primeiro da lista
            if ((current == list->first) && (current->info == data)) {
                list->first = current->next;
                free(current);
                current = list->first;
                list->size--;
            } else {
                //ultimo da lista
                if ((current == list->last) && (current->info == data)) {
                    list->last = previous;
                    list->last->next = NULL;
                    list->size--;
                    free(current);
                    break;
                }

                //meio da lista
                if (current->info == data) {
                    previous->next = current->next;
                    free(current);
                    list->size--;
                    current = previous->next;
                } else {
                    previous = current;
                    current = current->next;
                }
            }
        }

        return 1;
    }

    return -1;
}

int maxList(List* list) {
    Node* current = NULL;
    int result = -1;

    if (list != NULL) {
        current = list->first;
        result = current->info;
        for (current = list->first->next; current != NULL; current = current->next)
            if (current->info > result)
                result = current->info;
        return result;
    }
    
    return INT_MIN;
}

int lastList(List* list) {
    if (list != NULL)
        if (!isEmptyList(list))
            return list->last->info;

    return INT_MIN;
}

int firsttList(List* list) {
    if (list != NULL)
        if (!isEmptyList(list))
            return list->first->info;

    return INT_MIN;
}

int countLargerElementList(List* list, int data) {
    int result = 0;
    Node* tmp = NULL;

    if (list != NULL) {
        for (tmp = list->first; tmp != NULL; tmp = tmp->next)
            if (tmp->info > data)
                result++;
        return result;
    }

    return -1;
}

int sizeList(List* list) {
    if (list != NULL)
        return list->size;
    return -1;
}

int printList(List* list) {
    Node* current = NULL;
    int flag = 1;
    
    if (list == NULL)
        return -1;
    
    if (isEmptyList(list)) {
        printf("Lista vazia\n");
        return 0;
    }

    for (current = list->first; current != NULL; current = current->next) {
        if (flag) {
            printf("%d", current->info);
            flag = 0;
        } else 
            printf(" %d", current->info);
    }
    printf("\n");

    return 1;
}

int clearList(List* list) {
    Node* next = NULL;
    Node* current = NULL;

    if (list != NULL) {
        current = list->first;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        free(list);
        return 1;
    }

    return -1;
}

int emptyList(List* list) {
    Node* current = NULL;
    Node* next = NULL;

    if (list == NULL)
        return -1;

    current = list->first;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    list->first = NULL;
    list->last = NULL;
    list->size = 0;

    return 1;
}