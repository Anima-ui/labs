#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "validators.h"
#include "deque.h"

Deque* createDeque(int maxSize){
    Deque* d = malloc(sizeof(Deque));
    d->front = d->rear = NULL;
    d->size = 0;
    d->maxSize = maxSize;
    return d;
}

void pushFront(Deque* d, int value){
    if (d->size >= d->maxSize) {
        printf("Deque is full\n");
        return;
    }

    NodeD* newNode = malloc(sizeof(NodeD));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = d->front;

    if (d->front == NULL){
        d->rear = newNode;
    } else {
        d->front->prev = newNode;
    }

    d->front = newNode;
    d->size++;
}

void pushRear(Deque* d, int value){
    if (d->size >= d->maxSize) {
        printf("Deque is full\n");
        return;
    }

    NodeD* newNode = malloc(sizeof(NodeD));
    newNode->data = value;
    newNode->prev = d->rear;
    newNode->next = NULL;

    if (d->rear == NULL){
        d->front = newNode;
    } else {
        d->rear->next = newNode;
    }

    d->rear = newNode;
    d->size++;
}

int popBack(Deque* d){
    if (d->front == NULL) {
        printf("Deque is empty\n");
        return INT_MIN;
    }

    NodeD* temp = d->rear;
    int value = temp->data;

    d->rear = d->rear->prev;
    if (d->rear == NULL){
        d->front = NULL;
    } else {
        d->rear->next = NULL;
    }

    free(temp);
    d->size--;
    return value;
}

int popFront(Deque* d){
    if (d->front == NULL) {
        printf("Deque is empty\n");
        return INT_MIN;
    }

    NodeD* temp = d->front;
    int value = temp->data;

    d->front = d->front->next;
    if (d->front == NULL){
        d->rear = NULL;
    } else {
        d->front->prev = NULL;
    }

    free(temp);
    d->size--;
    return value;
}

void printDeque(Deque* d){
    printf("----------------Deque--------------\n");
    NodeD* current = d->front;
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("----------------Deque--------------\n");
}

void freeDeque(Deque* d){
    NodeD* current = d->front;
    while (current != NULL){
        NodeD* next = current->next;
        free(current);
        current = next;
    }
    free(d);
}

bool isDequeEmpty(Deque* d){
    return d->front == NULL;
}
