#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    float val;
    struct Node * next;
}Node;

typedef struct {
    Node * head;
    int len;
}NumsStack;

NumsStack * newNumStack() {
    NumsStack * newStack = malloc(sizeof(NumsStack));
    newStack->head = malloc(sizeof(Node));
    newStack->len = 0;
    return newStack;
}

void push(float v, NumsStack * stack) {
    Node * newOp = malloc(sizeof(Node));
    newOp->val = v;
    newOp->next = stack->head;
    if (stack->len < 1) {
        newOp->next = NULL;
    }
    stack->head = newOp;
    stack->len++;
}

float pop(NumsStack * stack) {
    if(stack->len < 1) {
        return -1;
    }
    if (stack->head == NULL) {
        return -1;
    }
    Node * temp;
    if (stack->head->next == NULL) {
        temp = stack->head;

        float v = temp->val;
        stack->head = NULL;
        stack->len--;
        return v;
    } else {
        temp = stack->head;
        stack->head = temp->next;
        float poppedChar = temp->val;
        stack->len--;
        return poppedChar;
    }
}

int isDigit(char val) {
    if (val >= '0' && val <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int isDigitOrOp(char val) {
    if (val >= '0' && val <= '9') {
        return 1;
    } else if (val == '+' || val == '-' || val == '*' || val == '/') {
        return 1;
    } 
    else {
        return 0;
    }
}

int isPartOfFloat(char val, char prev, char next, int isPrevOp) {
    if(isDigit(val) || (val == '.' && isDigit(prev) && isDigit(next)) || (isDigit(next) && val == '-')) {
        return 1;
    }
    return 0;
}

float calcWithRPN(char * postfix) {
    NumsStack * stack = newNumStack();
    int isPrevOp = 1;
    while(*postfix != '\0') {
        if(isPartOfFloat(*postfix, *(postfix-1), *(postfix+1), isPrevOp)) {
            char buf[32];
            int i = 0;
            isPrevOp = 0;
            while(isPartOfFloat(*postfix, *(postfix-1), *(postfix+1), isPrevOp)) {
                buf[i++] = *postfix;
                postfix++;
            }
            buf[i] = '\0';
            float num;
            sscanf(buf, "%f", &num);
            push(num, stack);
            //postfix++;
        } else {
            float a;
            float b;
            switch (*postfix)
            {
            case '+':
                a = pop(stack);
                b = pop(stack);
                push(a+b, stack);
                postfix++;
                break;

            case '-':
                a = pop(stack);
                b = pop(stack);
                push(b-a, stack);
                postfix++;
                break;
            
            case '*':
                a = pop(stack);
                b = pop(stack);
                push(a*b, stack);
                postfix++;
                break;
            
            case '/':
                a = pop(stack);
                b = pop(stack);
                push(b/a, stack);
                postfix++;
                break;
            default:
                postfix++;
                break;
            }
        }
    }
    float res = stack->head->val;
    free(stack);
    return res;
}