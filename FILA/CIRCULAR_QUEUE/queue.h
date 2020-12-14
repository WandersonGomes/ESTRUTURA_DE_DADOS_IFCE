#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue Queue;

Queue* createQueue();
int enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int frontQueue(Queue* queue);
int rearQueue(Queue* queue);
int isEmptyQueue(Queue* queue);
int sizeQueue(Queue* queue);
int printQueue(Queue* queue);
int destroyQueue(Queue* queue);

#endif