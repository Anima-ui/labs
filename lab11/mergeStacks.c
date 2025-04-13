#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "stack.h"

Stack * mergeStacks(Stack * s1, Stack * s2) {
    Node * currNodeS1 = s1->Head;
    Node * currNodeS2 = s2->Head;
    Stack * mergedStack = newStack();
    while(currNodeS1->Prev != NULL || currNodeS2->Prev != NULL) {
        if(currNodeS1->Val <= currNodeS2->Val) {
            Push(currNodeS1->Val, mergedStack);
            continue;
        }
        Push(currNodeS2->Val, mergedStack);
    }
    printf("MERGED STACK: \n");
    PrintStack(mergedStack);
    return mergedStack;
}