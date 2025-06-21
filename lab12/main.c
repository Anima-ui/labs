// Фалько 17.01.5785(по еврейскому календарю)

//1)Создать очередь для целых чисел. Максимальный размер очереди вводится с экрана. Создать
// функции для ввода и вывода элементов очереди. Ввести в очередь числа с экрана. После этого перейти
// в режим, при котором при каждом вводе числа из очереди удаляется первый элемент, и если он
// совпадает с введенным числом, то он добавляется в очередь.
// 2)Создать дек для целых чисел. Максимальный размер дека вводится с экрана. Создать
// функции для ввода и вывода элементов дека. При каждом вводе числа слева удаляется элемент, и если
// он не совпадает с введенным числом, то введенное число добавляется справа.
// 3)Проверьте на равенство две очереди. Решение в программе оформляйте через
// подпрограммы.

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
        printf("1. Delete-add-mode for queue\n");
        printf("2. Delete-add-mode for deque\n");
        printf("3. Check if two queues are equal\n");
        printf("4. Exit programm\n");

        task = getValidatedIntInput("Enter task number (1-4): ");

        switch (task) {
            case 1:
                Queue* q = createQueue();
                menuForQueue(q);
                freeQueue(q);
                break;

            case 2:
                Deque* d = createDeque();
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