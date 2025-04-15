#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "validators.h"
#include <stdbool.h>

void fillQueue(Queue* q);
bool isEqualHeadAndValue(Queue* q, int value);
void deleteAddMode(Queue* q);