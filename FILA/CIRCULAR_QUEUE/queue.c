#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR 0
#define ERROR_QUEUE_NOT_DEFINED "Queue not defined."
#define ERROR_NODE_NOT_CREATE "Node not create."

typedef struct node {
    int data;
    struct node* next;
} Node;

struct queue {
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
Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));

    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return NULL;
    }

    queue->size = 0;
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

int enqueue(Queue* queue, int data) {
    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return 0;
    }

    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        myLog(ERROR, ERROR_NODE_NOT_CREATE);
        return 0;
    }

    new->data = data;
    new->next = NULL;

    if (isEmptyQueue(queue)) {
        queue->front = new;
        queue->rear = new;
    } else {
        queue->rear->next = new;
        queue->rear = new;
    }
    
    queue->size++;

    return 1;
}

int dequeue(Queue* queue) {
    if (queue == NULL) {
        myLog(ERROR, ERROR_QUEUE_NOT_DEFINED);
        return 0;
    }

    if (isEmptyQueue(queue))
        return 0;
    
    Node* temporary = queue->front;
    int result = temporary->data;
    queue->front = queue->front->next;
    free(temporary);
    queue->size--;

    if (isEmptyQueue(queue))
        queue->rear = NULL;
    
    return result;
}

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

    while (isEmptyQueue(queue))
        dequeue(queue);

    free(queue);

    return 1;
}