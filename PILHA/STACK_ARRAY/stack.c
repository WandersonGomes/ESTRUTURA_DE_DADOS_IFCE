#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR 0
#define ERROR_STACK_NOT_DEFINED "Stack not defined."
#define ERROR_NODE_NOT_CREATE "Node not create."

struct stack {
    int size;
    int top;
    int* datas;
};

//AUXILIARY FUNCTION
void myLog(int type, char* message) {
    if (type == ERROR)
        fprintf(stderr, "Error: %s\n", message);
}

//MAIN FUNCTION
Stack* createStack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));

    if (stack == NULL) {
        myLog(ERROR, "Not create stack.");
        return NULL;
    }

    stack->datas = (int*) malloc(sizeof(int)*size);
    if (stack->datas == NULL) {
        myLog(ERROR, "Not create stack.");
        return NULL;
    }

    stack->size = 0;
    stack->top = -1;

    return stack;
}

int pushStack(Stack* stack, int data) {
    if (stack == NULL) {
        myLog(ERROR, ERROR_STACK_NOT_DEFINED);
        return 0;
    }

    stack->size++;
    stack->top++;
    stack->datas[stack->top] = data;

    return 1;
}

int popStack(Stack* stack) {
    if (stack == NULL) {
        myLog(ERROR, ERROR_STACK_NOT_DEFINED);
        return INT_MIN;
    }

    if (isEmptyStack(stack)) {
        return INT_MIN;
    }

    stack->size--;
    stack->top--;

    return stack->datas[stack->top + 1];
}

int peekStack(Stack* stack) {
    if (stack == NULL) {
        myLog(ERROR, ERROR_STACK_NOT_DEFINED);
        return INT_MIN;
    }

    if (isEmptyStack(stack)) {
        return INT_MIN;
    }

    return stack->datas[stack->top];
}

int isEmptyStack(Stack* stack) {
    if (stack == NULL) {
        myLog(ERROR, ERROR_STACK_NOT_DEFINED);
        return INT_MIN;
    }

    return (stack->size == 0);
}

int printStack(Stack* stack) {
    if (stack == NULL) {
        myLog(ERROR, ERROR_STACK_NOT_DEFINED);
        return INT_MIN;
    }

    if (isEmptyStack(stack)) {
        return INT_MIN;
    }

    int i = 0;
    for (i = stack->size - 1; i > -1; i--)
        printf(" %d", stack->datas[i]);
    
    return 1;
}

int destroyStack(Stack* stack) {
    free(stack);
    return 1;
}