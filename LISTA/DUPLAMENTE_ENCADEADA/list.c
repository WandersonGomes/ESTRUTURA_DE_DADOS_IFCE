#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define FALSE 0
#define TRUE 1

#define ERROR_LIST_NOT_IS_DEFINED "List not is defined."
#define ERROR_NOT_CREATE_NODE "Not create node."
#define ERROR_INDEX_OUT_LIMITS "Index out limits."

typedef struct node {
    struct node* previous;
    int data;
    struct node* next;
} Node;

struct list {
    int size;
    int circular;
    Node* start;
    Node* end;
};

//log
void myLog(char* message) {
    fprintf(stderr, "Error: %s\n", message);
}

//create
List* createList() {
    List* list = (List*) malloc(sizeof(List));

    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return NULL;
    }

    list->size = 0;
    list->circular = FALSE;
    list->start = NULL;
    list->end = NULL;

    return list;
}

//inserts
int insertStartList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        myLog(ERROR_NOT_CREATE_NODE);
        return 0;
    }
    new->data = data;
    new->next = NULL;
    new->previous = NULL;

    if (isEmptyList(list)) {
        list->start = new;
        list->end = new;
    } else {
        new->next = list->start;
        list->start->previous = new;
        list->start = new;
    }

    if (list->circular == TRUE) {
        list->end->next = list->start;
        list->start->previous = list->end;
    }

    list->size++;

    return 1;
}

int insertEndList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        myLog(ERROR_NOT_CREATE_NODE);
        return 0;
    }
    new->data = data;
    new->next = NULL;
    new->previous = NULL;

    if (isEmptyList(list)) {
        list->start = new;
        list->end = new;
    } else {
        list->end->next = new;
        new->previous = list->end;
        list->end = new;
    }

    if (list->circular == TRUE) {
        list->end->next = list->start;
        list->start->previous = list->end;
    }

    list->size++;

    return 1;
}

int insertSortList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list)) {
        insertStartList(list, data);
        return 1;
    }

    if (data <= list->start->data) {
        insertStartList(list, data);
        return 1;
    }

    Node* previous = list->start;
    Node* current = list->start->next;
    while ((current != NULL) && (current != list->start)) {
        if (current->data >= data)
            break;
        previous = current;
        current = current->next;
    }

    if ((current == NULL) || (current == list->start)) {
        insertEndList(list, data);
        return 1;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        myLog(ERROR_NOT_CREATE_NODE);
        return 0;
    }
    new->data = data;

    previous->next = new;
    new->previous = previous;
    new->next = current;
    current->previous = new;
   
    list->size++;

    return 1;
}

int insertIndexList(List* list, int index, int data) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if ((index < 0) || (index > sizeList(list))) {
        myLog(ERROR_INDEX_OUT_LIMITS);
        return 0;
    }

    if (index == 0) {
        insertStartList(list, data);
        return 1;
    }

    if (index == sizeList(list)) {
        insertEndList(list, data);
        return 1;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        myLog(ERROR_NOT_CREATE_NODE);
        return 0;
    }
    new->data = data;
    new->next = NULL;
    new->previous = NULL;

    Node* current = list->start;
    int i = 1;
    for (; i < index; i++)
        current = current->next;
    
    new->next = current->next;
    current->next->previous = new;
    current->next = new;
    new->previous = current;

    list->size++;

    return 1;
}

//consults
int isEmptyList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return -1;
    }

    return (list->size == 0);
}

int startList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return INT_MIN;
    }

    if (isEmptyList(list))
        return INT_MIN;

    return list->start->data;
}

int endList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return INT_MIN;
    }

    if (isEmptyList(list))
        return INT_MIN;

    return list->end->data;
}

int dataIndexList(List* list, int index) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return INT_MIN;
    }

    if (isEmptyList(list))
        return INT_MIN;

    if ((index < 0) || (index >= sizeList(list)))
        return INT_MIN;
    
    if (index == 0)
        return startList(list);
    
    if (index == (sizeList(list) - 1))
        return endList(list);
    
    Node* current = list->start;
    int i = 0;
    for (; i < index; i++)
        current = current->next;

    return current->data;
}

int sizeList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return INT_MIN;
    }

    return list->size;
}

//remove
int removeStartList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list))
        return 0;

    Node* tmp = NULL;
    if (sizeList(list) == 1) {
        free(list->start);
        list->end = NULL;
    } else {
        tmp = list->start;
        list->start = tmp->next;
        tmp->next->previous = NULL;
        if (list->circular == TRUE) {
            list->end->next = list->start;
            list->start->previous = list->end;
        }
        free(tmp);
    }

    list->size--;
    return 1;
}

int removeEndList(List* list) {
    return removeDataIndexList(list, sizeList(list) - 1);
}

int removeDataList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list))
        return 0;
    
    if (data == startList(list)) {
        removeStartList(list);
        return 1;
    }

    Node* previous = list->start;
    Node* current = list->start->next;
    while (current != NULL) {
        if (current->data == data)
            break;
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        previous->next = current->next;
        free(current);
        previous->next->previous = previous;
        if ((previous->next == NULL) || (previous->next == list->start))
            list->end = previous;

        list->size--;
    }

    return 1;
}

int removeAllDataList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list))
        return 0;
    
    Node* previous = NULL;
    Node* current = NULL;
    while (1) {
        if (data == startList(list)) {
            removeStartList(list);
            if (isEmptyList(list))
                return 1;
        } else {
            previous = list->start;
            current = list->start->next;
            while ((current != NULL) && (current != list->start)){
                if (current->data == data) {
                    previous->next = current->next;
                    previous->next->previous = previous;
                    free(current);
                    list->size--;
                    current = previous->next;
                    if ((current == NULL) || (current == list->start))
                        list->end = previous;
                } else {
                    previous = current;
                    current = current->next;
                }
            }

            return 1;
        }
    }
}

int removeDataIndexList(List* list, int index) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list))
        return 0;
    
    if ((index < 0) || (index >= sizeList(list))) {
        myLog(ERROR_INDEX_OUT_LIMITS);
        return 0;
    }

    if (index == 0) {
        removeStartList(list);
        return 1;
    }

    Node* current = list->start;
    Node* tmp = NULL;
    int i = 0;
    for (i = 1; i < index; i++)
        current = current->next;
    tmp = current->next;
    current->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->previous = current;
    free(tmp);

    
    if (current->next == NULL) {
        list->end = current;
        if (list->circular == TRUE) {
            list->end->next = list->start;
            list->start->previous = list->end;
        }
    }

    list->size--;

    return 1;
}

//clear
int clearList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    while (!isEmptyList(list))
        removeStartList(list);
    
    return 1;
}

//print
int printList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list))
        return 0;
    
    Node* current = list->start;
    do {
        printf(" %d", current->data);
        current = current->next;
    } while ((current != NULL) && (current != list->start));

    return 1;
}

int printLeftRightList(List* list) {
    return printList(list);
}

int printRightLeftList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list))
        return 0;
    
    Node* current = list->end;
    do {
        printf(" %d", current->data);
        current = current->previous;
    } while ((current != NULL) && (current != list->end));

    return 1;
}

//destroy
int destroyList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    clearList(list);
    free(list);
    return 1;  
}

//additional
int convertListToCircular(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (list->circular == TRUE)
        return 0;
    
    list->circular = TRUE;
    
    if (!isEmptyList(list)) {
        list->end->next = list->start;
        list->start->previous = list->end;
    }

    return 1;
}