#include "deque.h"
#include <stdio.h>

int main() {
    Deque* deque = NULL;
    int i = 0;

    printf("createDeque()\n");
    deque = createDeque();

    printf("pushRearDeque()\n");
    for (i = 1; i < 6; i++)
        pushRearDeque(deque, i);

    printf("printDeque()\n");
    printDeque(deque);
    printf("\n");

    printf("popFrontDeque()\n");
    popFrontDeque(deque);

    printf("printDeque()\n");
    printDeque(deque);
    printf("\n");

    while (!isEmptyDeque(deque)) {
        printf("popFrontDeque()\n");
        popFrontDeque(deque);
    }

    printf("printDeque()\n");
    printDeque(deque);
    printf("\n");

    printf("pushFrontDeque()\n");
    for (i = 1; i < 6; i++)
        pushFrontDeque(deque, i);

    printf("printDeque()\n");
    printDeque(deque);
    printf("\n");

    printf("popRearDeque()\n");
    popRearDeque(deque);

    printf("printDeque()\n");
    printDeque(deque);
    printf("\n");

    while (!isEmptyDeque(deque)) {
        printf("popRearDeque()\n");
        popRearDeque(deque);
    }

    printf("pushFrontDeque()\n");
    for (i = 1; i < 6; i++)
        pushFrontDeque(deque, i);

    printf("printDeque()\n");
    printDeque(deque);
    printf("\n");

    printf("frontDeque()\n");
    printf("%d\n", frontDeque(deque));

    printf("rearDeque()\n");
    printf("%d\n", rearDeque(deque));

    printf("destroyDeque()\n");
    destroyDeque(deque);

    return 0;
}