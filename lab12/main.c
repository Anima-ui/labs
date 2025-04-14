#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "validators.h"


int main() {
    int choice;

    Queue* q = createQueue();

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        choice = getValidatedIntInput("Enter your choice: ");

        switch (choice) {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printQueue(q);
                break;
            case 4:
                printf("Exiting...\n");
                freeQueue(q);  
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 4);

    return 0;
}