#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR 0
#define ERROR_STACK_NOT_DEFINED "Stack not defined."
#define ERROR_NODE_NOT_CREATE "Node not create."

typedef struct node {
    int data;
    struct node* next;
} Node;

struct stack {
    int size;
    Node* top;
};

//AUXILIARY FUNCTION
void myLog(int type, char* message) {
    if (type == ERROR)
        fprintf(stderr, "Error: %s\n", message);
}

//MAIN FUNCTION
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));

    if (stack == NULL) {
        myLog(ERROR, "Not create stack.");
        return NULL;
    }

    stack->size = 0;
    stack->top = NULL;

    return stack;
}

int pushStack(Stack* stack, int data) {
    if (stack == NULL) {
        myLog(ERROR, ERROR_STACK_NOT_DEFINED);
        return 0;
    }

    Node* new = (Node*) malloc(sizeof(Node));

    if (new == NULL) {
        myLog(ERROR, ERROR_NODE_NOT_CREATE);
        return 0;
    }

    new->data = data;
    new->next = stack->top;
    stack->top = new;
    stack->size++;

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

    Node* temporary = stack->top;
    int data = stack->top->data;
    stack->top = stack->top->next;
    free(temporary);
    stack->size--;

    return data;
}

int peekStack(Stack* stack) {
    if (stack == NULL) {
        myLog(ERROR, ERROR_STACK_NOT_DEFINED);
        return INT_MIN;
    }

    if (isEmptyStack(stack)) {
        return INT_MIN;
    }

    return stack->top->data;
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

    Node* current = NULL;
    for (current = stack->top; current != NULL; current = current->next)
        printf(" %d", current->data);
    
    return 1;
}

int destroyStack(Stack* stack) {
    while (!isEmptyStack(stack))
        popStack(stack);
    
    free(stack);
    return 1;
}