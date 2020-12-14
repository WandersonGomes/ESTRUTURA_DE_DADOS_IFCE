#include "queue.h"
#include <stdio.h>

int main() {
    Queue* queue = createQueue();
    int i = 0;

    for(; i < 11; i++)
        enqueue(queue, i);
    
    printf("Size Queue: %d\n", sizeQueue(queue));

    printf("Queue: ");
    printQueue(queue);
    printf("\n");

    printf("Dequeue.\n");
    dequeue(queue);

    printf("Queue: ");
    printQueue(queue);
    printf("\n");

    printf("Front Queue: %d\n", frontQueue(queue));
    printf("Rear Queue: %d\n", rearQueue(queue));
    
    printf("Enqueue 11\n");
    enqueue(queue, 11);

    printf("Queue: ");
    printQueue(queue);
    printf("\n");

    destroyQueue(queue);
    return 0;
}