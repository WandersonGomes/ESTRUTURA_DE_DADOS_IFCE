#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define ERROR 1
#define WARNING 0

typedef struct node {
    int data;
    struct node* next;
} Node;


struct list {
    int size;
    Node* start;
    Node* end;
};

//AUXILIARY FUNCTION
void myLog(int type, char* message) {
    if (type == ERROR)
        printf("Error: %s\n", message);
    if (type == WARNING)
        printf("Warning: %s\n", message);
}

//MAIN FUNCTION
List* createList() {
    List* tmp = (List*) malloc(sizeof(List));
    
    if (tmp == NULL) {
        myLog(ERROR, "createList()");
        return NULL;
    }

    tmp->size = 0;
    tmp->start = NULL;
    tmp->end = NULL;

    return tmp;
}

/*====================================================================*/
int insertStartList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    //create new node
    Node* new = (Node*) malloc(sizeof(Node));

    if (new == NULL) {
        myLog(ERROR, "New node not created.");
        return 0;
    }

    new->data = data;
    new->next = NULL;

    //add new node
    if (isEmptyList(list)) {
        list->start = new;
        list->end = new;
    } else {
        new->next = list->start;
        list->start = new;
    }

    list->size++;

    return 1; //successuful
}

int insertEndList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    //create new node
    Node* new = (Node*) malloc(sizeof(Node));

    if (new == NULL) {
        myLog(ERROR, "New node not created.");
        return 0;
    }

    new->data = data;
    new->next = NULL;

    //add new node
    if (isEmptyList(list)) {
        list->start = new;
        list->end = new;
    } else {
        list->end->next = new;
        list->end = new;
    }

    list->size++;

    return 1; //success
}

int insertIndexList(List* list, int index, int data) {
    int i = 0;
    Node* current = NULL;

    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    if ((index < 0) || (index > getSizeList(list))) {
        myLog(WARNING, "Index out of the limits.");
        return 0;
    }

    if (index == 0) {
        insertStartList(list, data);
        return 1;
    } else if (index == getSizeList(list)) {
        insertEndList(list, data);
        return 1;
    } else {
        current = list->start;
        for (i = 1; i < index; i++)
            current = current->next;
        
        Node* new = (Node*)malloc(sizeof(Node));

        if (new == NULL) {
            myLog(ERROR, "Node new not created.");
            return 0;
        }

        new->data = data;
        new->next = current->next;
        current->next = new;

        list->size++;

        return 1; //success
    }
}

int insertSortList(List* list, int data) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    //list empty
    if (isEmptyList(list)) {
        insertStartList(list, data);
        return 1;
    }

    //start list > data
    if (data <= getStartList(list)) {
        insertStartList(list, data);
        return 1;
    }

    //middle and end
    Node* current = list->start;
    while ((current != NULL) && (data > current->data))
        current = current->next;
    
    if (current == NULL) {
        insertEndList(list, data);
        return 1;
    }
    
    Node* new = (Node*) malloc(sizeof(Node));

    if (new == NULL) {
        myLog(ERROR, "New node not create.");
        return 0;
    }

    new->data = data;
    new->next = current->next;
    current->next = new;

    list->size++;

    return 1; //success
}

/*====================================================================*/
int isEmptyList(List* list) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.\n");
        return -1;
    }
    
    return (list->size == 0);
}

int getStartList(List* list) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return INT_MIN;
    }

    if (!isEmptyList(list))
        return list->start->data;
    
    return INT_MIN;
}

int getEndList(List* list) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return INT_MIN;
    }

    if (!isEmptyList(list))
        return list->end->data;
    
    return INT_MAX;
}

int getSizeList(List* list) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return -1;
    }
    
    return list->size;
}

int getElementIndexList(List* list, int index) {
    int i = 0;
    Node* current = NULL;

    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return INT_MIN;
    }

    if ((index < 0) || (index >= getSizeList(list))) {
        myLog(ERROR, "Index out of the limits.");
        return INT_MIN;
    }

    if (index == 0)
        return list->start->data;

    if (index == (getSizeList(list) - 1))
        return list->end->data;
    
    current = list->start;
    for (i = 0; i < index; i++)
        current = current->next;
    
    return current->data;
}

int getIndexElementList(List* list, int data) {
    int result = -1;
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return -1;
    }

    Node* current = NULL;
    for (current = list->start; current != NULL; current = current->next) {
        result++;
        if (current->data == data)
            return result;
    }

    return -1;
}

/*====================================================================*/
int removeElementStartList(List* list) {
    Node* tmp = NULL;

    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    if (isEmptyList(list)) {
        myLog(WARNING, "List empty.");
        return 0;
    }

    tmp = list->start;
    list->start = tmp->next;
    free(tmp);
    list->size--;

    if (isEmptyList(list))
        list->end = NULL;
    
    return 1;
}

int removeElementIndexList(List* list, int index) {
    int i = 0;
    Node* current = NULL;
    Node* temporary = NULL;

    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return INT_MIN;
    }

    if (isEmptyList(list)) {
        myLog(WARNING, "List empty.");
        return INT_MIN;
    }

    if ((index < 0) || (index >= getSizeList(list))) {
        myLog(ERROR, "Index out of the limits.");
        return INT_MIN;
    }

    if (index == 0)
        return removeElementStartList(list);

    current = list->start;
    for (i = 0; i < (index-1); i++)
        current = current->next;
    
    temporary = current->next;
    current->next = temporary->next;
    free(temporary);
    
    list->size--;

    return 1;
}

int removeDataList(List* list, int data) {
    Node* previous = NULL;
    Node* current = NULL;

    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    if (isEmptyList(list)) {
        myLog(WARNING, "List empty.");
        return 0;
    }

    while (1) {
        if (data == getStartList(list)) {
            removeElementStartList(list);
        } else {
            previous = list->start;
            current = previous->next;

            while (current != NULL) {
                if (current->data == data) {
                    previous->next = current->next;
                    free(current);
                    current == previous->next;
                    list->size--;
                } else {
                    previous = current;
                    current = current->next;
                }
            }

            break;
        }

        if (isEmptyList(list)) {
            break;
        }
    }
    
    return 1;
}

/*====================================================================*/
int printList(List* list) {
    Node* current = NULL;
    int flag = 1;

    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    if (!isEmptyList(list)) {
        for (current = list->start; current != NULL; current = current->next) {
            if (flag) {
                printf("%d", current->data);
                flag = 0;
            } else {
                printf(", %d", current->data);
            }
        }
    } else {
        myLog(WARNING, "List empty.");
    }
    printf("\n");

    return 1;
}

/*====================================================================*/
int destroyList(List* list) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    while (!isEmptyList(list))
        removeElementStartList(list);
    free(list);
}

int emptyList(List* list) {
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return 0;
    }

    while (!isEmptyList(list))
        removeElementStartList(list);
}

/*====================================================================*/
int maxValueList(List* list) {
    Node* current = NULL;
    int result = 0;
    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return INT_MIN;
    }

    if (!isEmptyList(list)) {
        result = list->start->data;
        for (current = list->start->next; current != NULL; current = current->next)
            if (result < current->data)
                result = current->data;
        
        return result;
    }

    return INT_MIN;
}

int countGreatValueList(List* list, int data) {
    Node* current = NULL;
    int result = 0;

    if (list == NULL) {
        myLog(ERROR, "List not defined.");
        return -1;
    }

    if (!isEmptyList(list)) {
        for (current = list->start; current != NULL; current = current->next)
            if (current->data > data)
                result++;
    }

    return result;
}