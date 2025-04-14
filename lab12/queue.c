
#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "queue.h"


Queue* createQueue(){
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    q->maxSize = getValidatedIntInput("Enter max size of queue: ");
    return q;
}

void enqueue(Queue* q){
    int value = getValidatedIntInput("Input the value: ");

    if (q->size >= q->maxSize){
        printf("The queue is full");
        return;
    }

    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->tail){
        q->tail->next = newNode;
    } else {
        q->head = newNode;
    }

    q->tail = newNode;
    q->size++;

    printf("Element %d was added to the queue\n", value);
}

void dequeue(Queue* q){
    if (q->head == NULL){
        printf("The queue is empty");
        return;
    }

    Node* temp = q->head;
    
    q->head = temp->next;
    if (q->head == NULL)
        q->tail = NULL;

    printf("The element %d was deleted\n", temp->data);
    free(temp);
    q->size--;
}

void printQueue(Queue* q){
    if (q->size == 0) {
        printf("The queue is empty\n");
        return;
    }

    Node* temp = q->head;
    for (int i = 0; i < q->size; ++i){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void freeQueue(Queue* q){
    Node* temp = q->head;

    while(temp != NULL){
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    free(q);
}