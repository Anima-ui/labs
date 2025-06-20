#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "funcs.h"
#include "union.h"

void checkIsOdd() {
    union code c;
    c.n = getValidatedIntInput("Insert any integer: ");
    if (c.n & 1) {
        printf("The number is odd\n");
    }
    else {
        printf("The number is even\n");
        printf("The number is even\n");
    }
}