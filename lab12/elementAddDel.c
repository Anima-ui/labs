#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "validators.h"
#include <stdbool.h>
#include "deque.h"

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

void deleteAddModeForQueue(Queue* q){
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


void fillDeque(Deque* d){
    if (d->size >= d->maxSize){
        printf("Deque is full\n");
        return;
    }

    while (d->size < d->maxSize){
        printf("Choose where to add the element:\n");
        printf("1. Add to the front\n");
        printf("2. Add to the rear\n");
        int choice = getValidatedIntInput("Input your choice(1-2): ");

        int value = getValidatedIntInput("Input the value to add: ");

        if (choice == 1){
            pushFront(d, value);
            printf("The value %d was added to the front\n", value);
        } else if (choice == 2){
            pushRear(d, value);
            printf("The value %d was added to the rear\n", value);
        } else {
            printf("Try again");
            continue;
        }
    }
    printDeque(d);
}

void deleteAddModeForDeque(Deque* d){
    printf("Entering delete-and-add mode. Enter -1 to exit.\n");

    while (!isDequeEmpty(d)){
        int value = getValidatedIntInput("Enter value to compare (-1 to exit): ");
        if (value == -1) {
            printf("Exiting delete-and-add mode.\n");
            break;
        }

        int frontValue = popFront(d);
        if (frontValue == INT_MIN){
            break;
        }

        if (frontValue != value){
            pushRear(d, value);
            printf("Value %d was added to the right\n", value);
        } else {
            printf("Value %d was not added to the right\n", value);
        }
        printDeque(d);
    }

    if (isDequeEmpty(d)){
        printf("Queue is now empty. Mode ended.\n");
    }
}