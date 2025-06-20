#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "stack.h"

Stack* newStack() {
    Stack* stack = malloc(sizeof(Stack));
    if (!stack) {
        perror("Failed to allocate memory for stack");
        exit(EXIT_FAILURE);
    }
    stack->Head = NULL;         
    stack->Len = 0;
    stack->MaxLen = getValidatedIntInput("Input max len of stack: ");
    return stack;
}


void Push(int val, Stack* stack) {
    if(stack->Len >= stack->MaxLen) {
        printf("Error: You've reached the maximum length of the stack\n");
        return;
    }
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->Val = val;
    newNode->Prev = stack->Head;
    newNode->Next = NULL;
    
    if (stack->Head != NULL) {
        stack->Head->Next = newNode;
    }
    stack->Head = newNode;
    stack->Len++;
}

Node* Pop(Stack* stack) {
    if (stack == NULL || stack->Head == NULL) {
        return NULL;
    }
    Node* popped = stack->Head;
    stack->Head = popped->Prev;
    if (stack->Head != NULL) {
        stack->Head->Next = NULL;
    }
    stack->Len--;
    return popped;
}

void PrintStack(Stack* stack) {
    Node* temp = stack->Head;
    while (temp != NULL) {
        printf("%d\n", temp->Val);
        temp = temp->Prev;
    }
}

void freeStack(Stack* stack) {
    if (!stack) return; 

    Node* current = stack->Head;
    while (current) {
        Node* temp = current;
        current = current->Prev;
        free(temp); 
    }

    free(stack); 
}

void FillStack(Stack* stack) {
    int ftInt = getValidatedIntInput("Choose stack type:\n 0 - increasing,\n 1 - decreasing,\n 2 - chaotic\nEnter num: ");
    fillingType ft = (fillingType)ftInt;
    switch (ft)
    {
    case INCREASING:
        for (int i = 0; i < stack->MaxLen; i++) {
            int val = getValidatedIntInput("Insert int value: ");
            if (stack->Len > 0 && val < stack->Head->Val) {
                printf("Error: Each value must be greater than the previous one\n");
                i--; 
                continue;
            }
            Push(val, stack);
        }
        break;
    case DECREASING:
        for (int i = 0; i < stack->MaxLen; i++) {
            int val = getValidatedIntInput("Insert int value: ");
            if (stack->Len > 0 && val > stack->Head->Val) {
                printf("Error: Each value must be smaller than the previous one\n");
                i--;
                continue;
            }
            Push(val, stack);
        }
        break;
    case CHAOTIC:
        for (int i = 0; i < stack->MaxLen; i++) {
            int val = getValidatedIntInput("Insert int value: ");
            Push(val, stack);
        }
        break;
    default:
        printf("Invalid stack type selected.\n");
        break;
    }
}