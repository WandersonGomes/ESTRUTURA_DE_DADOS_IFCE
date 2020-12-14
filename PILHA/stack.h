#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack* createStack();
int pushStack(Stack* stack, int data);
int popStack(Stack* stack);
int isEmptyStack(Stack* stack);
int printStack(Stack* stack);
int peekStack(Stack* stack);
int destroyStack(Stack* stack);

#endif