#pragma once
#include <stdbool.h>

typedef struct NodeQ{
    int data;
    struct NodeQ* next;
} NodeQ;

typedef struct Queue{
    NodeQ* head;
    NodeQ* tail;
    int size;
    int maxSize;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void printQueue(Queue* q);
void freeQueue(Queue* q);
bool isQueueEmpty(Queue* q);
