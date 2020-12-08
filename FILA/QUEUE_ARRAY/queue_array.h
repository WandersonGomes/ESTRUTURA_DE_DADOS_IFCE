#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

typedef struct queue Queue;

Queue* createQueue(unsigned capacity);
int sizeQueue(Queue* queue);
int isEmptyQueue(Queue* queue);
void enQueue(Queue* queue, int valor);
int deQueue(Queue* queue);
int frontQueue(Queue* queue);
int rearQueue(Queue* queue);
void printQueue(Queue* queue);
void destroyQueue(Queue* queue);

#endif