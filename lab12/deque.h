#pragma once

typedef struct NodeD{
    int data;
    struct NodeD* next;
    struct NodeD* prev;   
} NodeD;


typedef struct Deque{
    NodeD* front;
    NodeD* rear;
    int size;
} Deque;

Deque* createDeque();
void pushFront(Deque* d, int value);
void pushRear(Deque* d, int value);
int popBack(Deque* d);
int popFront(Deque* d);
void printDeque(Deque* d);
void freeDeque(Deque* d);
bool isDequeEmpty(Deque* d);