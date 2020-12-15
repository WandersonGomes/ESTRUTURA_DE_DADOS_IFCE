#include "deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR 0
#define ERROR_DEQUE_NOT_DEFINED "Deque is not defined."
#define ERROR_NODE_NOT_CREATE "Node not create."

typedef struct node {
    struct node* previous;
    int data;
    struct node* next;
} Node;

struct deque {
    int size;
    Node* front;
    Node* rear;
};

//AUXILIARY FUNCTION
void myLog(int type, char* message) {
    if (type == ERROR)
        fprintf(stderr, "Error: %s\n", message);
}

//MAIN FUNCTION
Deque* createDeque() {
    Deque* deque = (Deque*) malloc(sizeof(Deque));

    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return NULL;
    }

    deque->size = 0;
    deque->front = NULL;
    deque->rear = NULL;

    return deque;
}

int pushRearDeque(Deque* deque, int data) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return 0;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        myLog(ERROR, ERROR_NODE_NOT_CREATE);
        return 0;
    }

    new->data = data;
    new->next = NULL;
    new->previous = NULL;

    if (isEmptyDeque(deque)) {
        deque->front = new;
        deque->rear = new;
    } else {
        deque->rear->next = new;
        new->previous = deque->rear;
        deque->rear = new;
    }
    
    deque->size++;

    return 1;
}

int pushFrontDeque(Deque* deque, int data) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return 0;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        myLog(ERROR, ERROR_NODE_NOT_CREATE);
        return 0;
    }

    new->data = data;
    new->next = NULL;
    new->previous = NULL;

    if (isEmptyDeque(deque)) {
        deque->front = new;
        deque->rear = new;
    } else {
        new->next = deque->front;
        deque->front->previous = new;
        deque->front = new;
    }

    deque->size++;

    return 1;
}

int popFrontDeque(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return 0;
    }

    if (isEmptyDeque(deque))
        return 0;

    Node* temporary = deque->front;
    int result = temporary->data;
    deque->front = deque->front->next;
    
    if (deque->front != NULL)
        deque->front->previous = NULL;
    
    free(temporary);
    deque->size--;

    if (isEmptyDeque(deque))
        deque->rear = NULL;
    
    return result;
}

int popRearDeque(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return 0;
    }

    if (isEmptyDeque(deque))
        return 0;
    
    Node* temporary = deque->rear;
    int result = temporary->data;
    
    if (deque->rear->previous != NULL)
        deque->rear->previous->next = NULL;
    deque->rear = deque->rear->previous;
    
    free(temporary);
    deque->size--;

    if (isEmptyDeque(deque))
        deque->front = NULL;
    
    return result;
}

int frontDeque(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return INT_MIN;
    }

    if (isEmptyDeque(deque))
        return INT_MIN;
    
    return deque->front->data;
}

int rearDeque(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return INT_MIN;
    }

    if (isEmptyDeque(deque))
        return INT_MIN;
    
    return deque->rear->data;
}

int isEmptyDeque(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return -1;
    }
    
    return (deque->size == 0);
}

int sizeDeque(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return INT_MIN;
    }
    
    return deque->size;
}

int printDeque(Deque* deque) {
    return printDequeLeftRight(deque);
}

int printDequeLeftRight(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return 0;
    }

    if (isEmptyDeque(deque))
        return 0;
    
    Node* current = NULL;
    for(current = deque->front; current != NULL; current = current->next)
        printf(" %d", current->data);
    
    return 1;
}

int printDequeRightLeft(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return 0;
    }

    if (isEmptyDeque(deque))
        return 0;
    
    Node* current = NULL;
    for(current = deque->rear; current != NULL; current = current->previous)
        printf(" %d", current->data);
    
    return 1;
}

int destroyDeque(Deque* deque) {
    if (deque == NULL) {
        myLog(ERROR, ERROR_DEQUE_NOT_DEFINED);
        return 0;
    }

    while (!isEmptyDeque(deque))
        popFrontDeque(deque);

    free(deque);

    return 1;
}