#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue* createQueue();
int pushQueue(Queue* queue, int data);
int popQueue(Queue* queue);
int frontQueue(Queue* queue);
int rearQueue(Queue* queue);
int isEmptyQueue(Queue* queue);
int sizeQueue(Queue* queue);
int printQueue(Queue* queue);
int destroyQueue(Queue* queue);

#endif