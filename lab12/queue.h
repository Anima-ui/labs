#pragma once

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
void enqueue(Queue* q);
void dequeue(Queue* q);
void printQueue(Queue* q);
void freeQueue(Queue* q);
