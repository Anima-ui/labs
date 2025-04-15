#pragma once
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* head;
    Node* tail;
    int size;
    int maxSize;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void printQueue(Queue* q);
void freeQueue(Queue* q);
bool isQueueEmpty(Queue* q);
