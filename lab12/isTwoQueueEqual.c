#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stdbool.h"

bool isSizeEqual(Queue* q1, Queue* q2){
    return q1->size == q2->size;
}

bool isQueueEqual(Queue* q1, Queue* q2){
    if (!isSizeEqual(q1, q2)) return false;

    NodeQ* currentQ1 = q1->head;
    NodeQ* currentQ2 = q2->head;

    while (currentQ1 != NULL && currentQ2 != NULL){
        if (currentQ1->data != currentQ2->data) return false;

        currentQ1 = currentQ1->next;
        currentQ2 = currentQ2->next;
    }
    return true;
}