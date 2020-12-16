#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define FALSE 0
#define TRUE 1

#define ERROR_LIST_NOT_IS_DEFINED "List not is defined."
#define ERROR_NOT_CREATE_NODE "Not create node."
#define ERROR_INDEX_OUT_LIMITS "Index out limits."

typedef struct node {
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

    if (isEmptyList(list)) {
        list->start = new;
        list->end = new;
    } else {
        new->next = list->start;
        list->start = new;
    }

    if (list->circular == TRUE)
        list->end->next = list->start;
    
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

    if (isEmptyList(list)) {
        list->start = new;
        list->end = new;
    } else {
        list->end->next = new;
        list->end = new;
    }

    if (list->circular == TRUE)
        list->end->next = list->start;
    
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
    new->next = current;
   
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

    Node* current = list->start;
    int i = 1;
    for (; i < index; i++)
        current = current->next;
    
    new->next = current->next;
    current->next = new;

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
        if (list->circular == TRUE)
            list->end->next = list->start;
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
    free(tmp);
    
    if (current->next == NULL) {
        list->end = current;
        if (list->circular == TRUE)
            list->end->next = list->start;
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
int maxDataList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return INT_MIN;
    }

    if (isEmptyList(list))
        return INT_MIN;

    Node* current = list->start;
    int max = current->data;
    current = current->next;
    while ((current != NULL) && (current != list->start)) {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }

    return max;
}

int minDataList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return INT_MIN;
    }

    if (isEmptyList(list))
        return INT_MIN;

    Node* current = list->start;
    int min = current->data;
    current = current->next;
    while ((current != NULL) && (current != list->start)) {
        if (current->data < min)
            min = current->data;
        current = current->next;
    }

    return min;
}

int countLargerDataList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list))
        return 0;

    Node* current = list->start;
    int count = 0;
    do {
        if (current->data > data)
            count++;
        current = current->next;
    } while ((current != NULL) && (current != list->start));

    return count;
}

//challenge
List* mergeList(List* list1, List* list2) {
    if ((list1 == NULL) || (list2 == NULL)) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return NULL;
    }

    List* result = createList();
    while (!isEmptyList(list1) && !isEmptyList(list2)) {
        insertEndList(result, startList(list1));
        insertEndList(result, startList(list2));
        removeStartList(list1);
        removeStartList(list2);
    }

    while (!isEmptyList(list1)) {
        insertEndList(result, startList(list1));
        removeStartList(list1);
    }
    
    while (!isEmptyList(list2)) {
        insertEndList(result, startList(list2));
        removeStartList(list2);
    }

    destroyList(list1);
    destroyList(list2);
    
    return result;
}

int reverseList(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (isEmptyList(list))
        return 0;

    if (sizeList(list) == 1)
        return 1;
    
    Node* tmp_start = list->start;
    Node* previous = NULL;
    Node* current = list->start;
    Node* next = current->next;

    while ((next != NULL) && (next != tmp_start)) {
        current->next = previous; //linka para o anterior
        previous = current; //atualiza o anterior
        current = next; //atualiza o corrente
        next = current->next; //atualiza o proximo
    }

    current->next = previous;
    list->start = current;
    list->end = tmp_start;
    if (list->circular == TRUE)
        list->end->next = list->start;

    return 1;
}

int convertListToCircular(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (list->circular == TRUE)
        return 0;
    
    list->circular = TRUE;
    
    if (!isEmptyList(list))
        list->end->next = list->start;
    return 1;
}

void reverse(Node* p, List* list) {
    if ((p->next == NULL) || (p->next == list->start)) {
        list->end = list->start;
        list->start = p;
        return;
    }
    reverse(p->next, list);
    Node* tmp = p->next;
    tmp->next = p;
    p->next = NULL;
}

int reverseListCircularRecursive(List* list) {
    if (list == NULL) {
        myLog(ERROR_LIST_NOT_IS_DEFINED);
        return 0;
    }

    if (list->circular == FALSE)
        return 0;

    if (isEmptyList(list))
        return 0;
    
    if (sizeList(list) == 1)
        return 1;

    reverse(list->start, list);

    return 1;
}