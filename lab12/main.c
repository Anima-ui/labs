#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "validators.h"
#include "elementAddDel.h"

void menu(Queue* q) {
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
                deleteAddMode(q);
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
                menu(q);
                freeQueue(q);
                break;

            case 2:
                Queue* q2 = createQueue();
                freeQueue(q2);
                break;

            case 3:
                Queue* q3 = createQueue();
                freeQueue(q3);
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