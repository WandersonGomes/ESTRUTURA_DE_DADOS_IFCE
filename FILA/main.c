#include "queue.h"
#include <stdio.h>

int main() {
    Queue* queue = createQueue();
    int i = 0;

    for(; i < 11; i++)
        pushQueue(queue, i);
    
    printf("Size Queue: %d\n", sizeQueue(queue));

    printf("Queue: ");
    printQueue(queue);
    printf("\n");

    printf("Pop Queue.\n");
    popQueue(queue);

    printf("Queue: ");
    printQueue(queue);
    printf("\n");

    printf("Front Queue: %d\n", frontQueue(queue));
    printf("Rear Queue: %d\n", rearQueue(queue));
    
    printf("Push 11\n");
    pushQueue(queue, 11);

    printf("Queue: ");
    printQueue(queue);
    printf("\n");

    destroyQueue(queue);
    return 0;
}