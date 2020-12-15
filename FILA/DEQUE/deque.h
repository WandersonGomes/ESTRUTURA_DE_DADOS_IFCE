#ifndef DEQUE_H
#define DEQUE_H

typedef struct deque Deque;

Deque* createDeque(); //ok
int pushRearDeque(Deque* deque, int data);
int pushFrontDeque(Deque* deque, int data);
int popFrontDeque(Deque* deque);
int popRearDeque(Deque* deque);

int frontDeque(Deque* deque);
int rearDeque(Deque* deque);

int isEmptyDeque(Deque* deque);
int sizeDeque(Deque* deque);

int printDeque(Deque* deque);
int printDequeLeftRight(Deque* deque);
int printDequeRightLeft(Deque* deque);
int destroyDeque(Deque* deque);

#endif