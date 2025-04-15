#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "validators.h"
#include <stdbool.h>
#include "deque.h"

void fillQueue(Queue* q);
bool isEqualHeadAndValue(Queue* q, int value);
void deleteAddModeForQueue(Queue* q);
void fillDeque(Deque* d);
void deleteAddModeForDeque(Deque* d);