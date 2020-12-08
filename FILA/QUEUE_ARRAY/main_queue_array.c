/*
Estudo baseado no video:
https://www.youtube.com/watch?v=q5oOYxfOD1c&t=701s
*/
#include <stdio.h>
#include "queue_array.h"

int main() {
    Queue* queue = createQueue(10);
    int i = 1;

    printQueue(queue);

    for (; i < 11; i++) {
        printf("%d enqueued to queue\n", i*10);
        enQueue(queue, i*10);
        printQueue(queue);
    }
    
    printf("%d dequeued from queue\n", deQueue(queue));
    printQueue(queue);

    enQueue(queue, i*10);
    printQueue(queue);

    printf("Front item is %d\n", frontQueue(queue));
    printf("Rear item is %d\n", rearQueue(queue));

    destroyQueue(queue);
    return 0;
}