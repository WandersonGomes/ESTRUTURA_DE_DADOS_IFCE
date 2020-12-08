#include "queue_array.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct queue {
 unsigned capacity;
 int front;
 int rear;
 int size;
 int* array;
};

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    queue->array = (int*) malloc(capacity*sizeof(int));
    return queue;
}

int sizeQueue(Queue* queue) {
    return queue->size;
}

int isEmptyQueue(Queue* queue) {
    return (queue->size == 0);
}

int isFullQueue(Queue* queue) {
    return (queue->size == queue->capacity);
}

void enQueue(Queue* queue, int valor) {
    if (isFullQueue(queue))
        return;
    queue->array[queue->rear] = valor;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->size++;
}

int deQueue(Queue* queue) {
    if (isEmptyQueue(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size--;
    return item;
}

int frontQueue(Queue* queue) {
    if (isEmptyQueue(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rearQueue(Queue* queue) {
    if (isEmptyQueue(queue))
        return INT_MIN;
    return queue->array[queue->rear - 1];
}

void destroyQueue(Queue* queue) {
    free(queue->array);
    free(queue);
}

void printQueue(Queue* queue) {
    printf("Queue = ");
    if (isEmptyQueue(queue)) {
        printf("empty!\n");
        return;
    }

    int begin = queue->front;
    int end = queue->rear;

    printf("%d", queue->array[begin]);
    begin = (begin+1) % queue->capacity;
    while (begin != end) {
        printf(", %d", queue->array[begin]);
        begin = (begin+1) % queue->capacity;
    }
    printf(".\n");
}