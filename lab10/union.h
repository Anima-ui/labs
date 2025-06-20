#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "funcs.h"

union code {
    int n;
    struct {
        unsigned int a0:1;
    }bit;
};

void checkIsOdd();