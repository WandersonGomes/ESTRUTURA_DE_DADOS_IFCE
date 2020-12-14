#ifndef DEQUEUE_H
#define DEQUEUE_H

typedef struct dequeue Dequeue;

Dequeue* createDequeue();
int pushRearDequeue(Dequeue* dequeue, int data);
int pushFrontDequeue(Dequeue* dequeue, int data);
int popFrontDequeue(Dequeue* dequeue);
int popRearDequeue(Dequeue* dequeue);

int frontDequeue(Dequeue* dequeue);
int rearDequeue(Dequeue* dequeue);
int isEmptyDequeue(Dequeue* dequeue);
int sizeDequeue(Dequeue* dequeue);
int printDequeue(Dequeue* dequeue);
int destroyDequeue(Dequeue* dequeue);

#endif