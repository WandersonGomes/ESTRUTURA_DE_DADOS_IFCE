#include "stack.h"
#include <stdio.h>

int main() {
    Stack* stack = createStack();
    int i = 0;

    for(i = 1; i < 11; i++)
        pushStack(stack, i);
    
    printf("Stack:");
    printStack(stack);
    printf("\n");

    printf("Top: %d\n", peekStack(stack));

    while (!isEmptyStack(stack)) {
        popStack(stack);
        printf("Stack:");
        printStack(stack);
        printf("\n");
    }
    popStack(stack);

    printf("TOPO: %d\n", peekStack(stack));
    destroyStack(stack);
    return 0;
}