#include <stdlib.h>
#include <stdio.h>
#include "Errors.h"

typedef struct Node{
    char val;
    struct Node* next;
}Node;

typedef struct {
    Node* head;
    int len;
}OpsStack;

OpsStack* newCharStack() {
    OpsStack* newStack = malloc(sizeof(OpsStack));
    newStack->head = malloc(sizeof(Node));
    newStack->len = 0;
    return newStack;
}

void printStack(OpsStack* stack) {
    Node* temp = stack->head;
    while(temp != NULL) {
        printf("%c", temp->val);
        temp = temp->next;        
    }
    printf("\n");
}

void pushOp(char v, OpsStack* stack) {
    Node* newOp = malloc(sizeof(Node));
    newOp->val = v;
    newOp->next = stack->head;
    if (stack->len < 1) {
        newOp->next = NULL;
    }
    stack->head = newOp;
    stack->len++;
}

char popOp(OpsStack* stack) {
    if(stack->len < 1) {
        return -1;
    }
    if (stack->head == NULL) {
        return -1;
    }
    Node* temp;
    if (stack->head->next == NULL) {
        temp = stack->head;

        char v = temp->val;
        stack->head = NULL;
        stack->len--;
        return v;
    } else {
        temp = stack->head;
        stack->head = temp->next;
        char poppedChar = temp->val;
        free(temp);
        stack->len--;
        return poppedChar;
    }
}

int isNum(char val) {
    if (val >= '0' && val <= '9') {
        return 1;
    } else {
        return 0;
    }
}

Node* getHeadNode(OpsStack* stack) {
    return stack->head;
}


short getPrecedence(char op) {
    switch (op)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '(':
        return 1;
        break;
    default:
        return -1;
    }
}

static int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


errorsList*  convertInfixToPostfix(char * infix, char * postfix, int currentLine) {
    errorsList* errList = newErrorsList();
    OpsStack* stack = newCharStack();
    int isPrevOp = 1;
    char *originalStart = infix;
    int currentIndex = 0;
    char * errText = malloc(sizeof(char) * 1024);
    while(*infix != '\0') {
        currentIndex = infix - originalStart;
        if(*infix == ' ') {
            infix++;
            continue;
        } else if(isNum(*infix) || *infix=='.') {
            *postfix = *infix;
            postfix++;
            infix++;
            isPrevOp = 0;
        } else if (!isNum(*infix)) {
            if(isPrevOp && *infix == '-') {
                *postfix = *infix;
                postfix++;
                infix++;
                continue;
            }
            *postfix = ' ';
            postfix++;
            Node* headNode = stack->head;
            switch (*infix)
            {
            case '(':
                pushOp(*infix, stack);
                infix++;
                break;
            case ')':
                char popped;
                while ((popped = popOp(stack)) != '(') {
                    if(popped == -1) {
                        errList = addError(errList, "Mismatched closing parenthesis", currentIndex, currentLine);
                    } 
                    *postfix = popped;
                    postfix++;
                }
                isPrevOp = 0;
                infix++;
                break;
            default:
                if(isPrevOp) {
                    errList = addError(errList, "Invalid operation place", currentIndex, currentLine);
                }
                if (!isOperator(*infix)) {
                    errList = addError(errList, "Invalid symbol", currentIndex, currentLine);
                }
                while (stack->head != NULL && getPrecedence(*infix) <= getPrecedence(stack->head->val)) {
                    *postfix = popOp(stack);
                    postfix++;
                    *postfix = ' ';
                    postfix++;
                }
                pushOp(*infix, stack);
                infix++;
                isPrevOp = 1;
                break;
            }
        }
    }
    currentIndex++;
    if(isPrevOp) {
        errList = addError(errList, "Invalid operation place", currentIndex, currentLine);
    }
    if(stack->len > 0) {
        while(stack->len > 0) {
            *postfix = popOp(stack);
            if(*postfix == '(') {
                errList = addError(errList, "Mismatched closing parenthesis", currentIndex, currentLine);
            }
            postfix++;
        }
    }
    *postfix='\0';
    free(stack);
    return errList;
}