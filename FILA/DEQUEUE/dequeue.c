#include "dequeue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR 0
#define ERROR_DEQUEUE_NOT_DEFINED "Dequeue not defined."
#define ERROR_NODE_NOT_CREATE "Node not create."

typedef struct node {
    int data;
    struct node* next;
} Node;

struct dequeue {
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
Dequeue* createDequeue() {
    Dequeue* dequeue = (Dequeue*) malloc(sizeof(Dequeue));

    if (dequeue == NULL) {
        myLog(ERROR, ERROR_DEQUEUE_NOT_DEFINED);
        return NULL;
    }

    dequeue->size = 0;
    dequeue->front = NULL;
    dequeue->rear = NULL;

    return dequeue;
}

int pushRearDequeue(Dequeue* dequeue, int data) {
    if (dequeue == NULL) {
        myLog(ERROR, ERROR_DEQUEUE_NOT_DEFINED);
        return 0;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        myLog(ERROR, ERROR_NODE_NOT_CREATE);
        return 0;
    }

    new->data = data;
    new->next = NULL;

    if (isEmptyDequeue(dequeue)) {
        dequeue->front = new;
        dequeue->rear = new;
    } else {
        dequeue->rear->next = new;
        dequeue->rear = new;
    }
    
    dequeue->size++;

    return 1;
}

int popFrontDequeue(Dequeue* dequeue) {
    if (dequeue == NULL) {
        myLog(ERROR, ERROR_DEQUEUE_NOT_DEFINED);
        return 0;
    }

    if (isEmptyDequeue(dequeue))
        return 0;
    
    Node* temporary = dequeue->front;
    int result = temporary->data;
    dequeue->front = dequeue->front->next;
    free(temporary);
    dequeue->size--;

    if (isEmptyDequeue(dequeue))
        dequeue->rear = NULL;
    
    return result;
}

//PAREI AQUI
int frontQueue(Queue* queue) {
    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return INT_MIN;
    }

    if (isEmptyQueue(queue))
        return INT_MIN;
    
    return queue->front->data;
}

int rearQueue(Queue* queue) {
    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return INT_MIN;
    }

    if (isEmptyQueue(queue))
        return INT_MIN;
    
    return queue->rear->data;
}

int isEmptyQueue(Queue* queue) {
    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return -1;
    }
    
    return (queue->size == 0);
}

int sizeQueue(Queue* queue) {
    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return INT_MIN;
    }
    
    return queue->size;
}

int printQueue(Queue* queue) {
    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return 0;
    }

    if (isEmptyQueue(queue))
        return 0;
    
    Node* current = NULL;
    for(current = queue->front; current != NULL; current = current->next)
        printf(" %d", current->data);
    
    return 1;
}

int destroyQueue(Queue* queue) {
    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return 0;
    }

    while (!isEmptyQueue(queue))
        dequeue(queue);

    free(queue);

    return 1;
}