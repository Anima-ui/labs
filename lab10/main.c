#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"
#include "union.h"
#include "storage.h"

int main() {
    char validChars[3] = { '1', '2', '3' };
    char choice;
    
    do {
        choice = getValidatedCharInput(
            "Choose the task:\n"
            " 1 - check if the number is odd or even\n"
            " 2 - book storage\n"
            " 3 - exit\n",
            validChars, 3);

        switch (choice) {
            case '1':
                checkIsOdd();
                break;
            case '2':
                bookStorage();
                break;
            case '3':
                printf("Exiting the program.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}