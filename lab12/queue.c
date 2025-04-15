
#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "queue.h"
#include <stdbool.h>


Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    q->maxSize = getValidatedIntInput("Enter max size of queue: ");
    return q;
}


void enqueue(Queue* q, int value){
    if (q->size >= q->maxSize) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }

    NodeQ* newNode = malloc(sizeof(NodeQ));
    newNode->data = value;
    newNode->next = NULL;

    if (q->tail != NULL) {
        q->tail->next = newNode;
    } else {
        q->head = newNode;
    }
    q->tail = newNode;
    q->size++;
}

int dequeue(Queue* q){
    if (q->head == NULL){
        printf("The queue is empty\n");
        return INT_MIN;
    }

    NodeQ* temp = q->head;
    int value = temp->data;
    
    q->head = temp->next;
    if (q->head == NULL)
        q->tail = NULL;

    printf("The head %d was deleted\n", temp->data);
    free(temp);
    q->size--;

    return value;
}

void printQueue(Queue* q){
    printf("---------------Queue----------------\n");
    if (q->size == 0) {
        printf("The queue is empty\n");
        return;
    }

    NodeQ* temp = q->head;
    for (int i = 0; i < q->size; ++i){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("---------------Queue----------------\n");
}

void freeQueue(Queue* q){
    NodeQ* temp = q->head;

    while(temp != NULL){
        NodeQ* next = temp->next;
        free(temp);
        temp = next;
    }

    free(q);
}

bool isQueueEmpty(Queue* q){
    return q->head == NULL;
}