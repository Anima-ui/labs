#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "deque.h"
#include "validators.h"
#include "elementAddDel.h"
#include "isTwoQueueEqual.h"

void menuForQueue(Queue* q) {
    int choice;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Fill the queue\n");
        printf("2. Print the queue\n");
        printf("3. Exit\n");

        choice = getValidatedIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                fillQueue(q);
                deleteAddModeForQueue(q);
                break;
            case 2:
                printQueue(q);
                break;
            case 3:
                printf("Exiting menu...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }

    } while (choice != 3);
}

void menuForDeque(Deque* d) {
    int choice;

    do {
        printf("\n--- Deque Menu ---\n");
        printf("1. Fill the deque\n");
        printf("2. Print the deque\n");
        printf("3. Exit\n");

        choice = getValidatedIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                fillDeque(d);
                deleteAddModeForDeque(d);
                break;
            case 2:
                printDeque(d);
                break;
            case 3:
                printf("Exiting menu...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }

    } while (choice != 3);
}

int main() {
    int task;

    do{
        printf("Select task:\n");
        printf("1. Task 1\n");
        printf("2. Task 2\n");
        printf("3. Task 3\n");
        printf("4. Exit programm\n");

        task = getValidatedIntInput("Enter task number (1-4): ");

        switch (task) {
            case 1:
                Queue* q = createQueue();
                menuForQueue(q);
                freeQueue(q);
                break;

            case 2:
                int maxSize = getValidatedIntInput("Input max size of deque: ");
                Deque* d = createDeque(maxSize);
                menuForDeque(d);
                freeDeque(d);
                break;

            case 3:
                Queue* q1 = createQueue();
                fillQueue(q1);
                Queue* q2 = createQueue();
                fillQueue(q2);

                printQueue(q1);
                printQueue(q2);

                if (isQueueEqual(q1, q2)){
                    printf("\nQueues are equal\n");
                } else {
                    printf("\nQueues are not equal\n");
                }

                freeQueue(q1);
                freeQueue(q2);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid task number\n");
                break;
        } 
    } while (task != 4);
    return 0;
}