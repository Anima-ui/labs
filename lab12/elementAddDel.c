#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "validators.h"
#include <stdbool.h>

void fillQueue(Queue* q){
    if (q->size >= q->maxSize){
        printf("Queue is full\n");
        return;
    }

    while(q->size < q->maxSize){
        int value = getValidatedIntInput("Input the value: ");
        enqueue(q, value);
    }
}

bool isEqualHeadAndValue(Queue* q, int value){
    return q->head != NULL && q->head->data == value;
}

void deleteAddMode(Queue* q){
    printf("Entering delete-and-add mode. Enter -1 to exit.\n");

    while (!isQueueEmpty(q)) {
        int value = getValidatedIntInput("Input the value to compare (-1 to exit): ");
        if (value == -1) {
            printf("Exiting delete-and-add mode.\n");
            break;
        }

        int head = dequeue(q);
        if (head == INT_MIN){
            break;
        }

        if (head == value){
            enqueue(q, value);
            printf("Value %d was added\n", value);
        } else {
            printf("Value %d was not added\n", value);
        }
        printQueue(q);
    }

    if (isQueueEmpty(q)){
        printf("Queue is now empty. Mode ended.\n");
    }
}

