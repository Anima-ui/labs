//Вариант 6      Фалько 11.04.2025
//
//1)Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти сумму
//до максимального элемента стека.
//2)Создать два стека для целых чисел. Первый стек – организовать ввод по убыванию, второй
// стек – организовать ввод по убыванию. Без сортировок и переворачивания исходных стеков
// сформировать третий стек упорядоченный по возрастанию
//3) В текстовом файле записаны строки – арифметические выражения. Числа – вещественные,
// знаки действий - -, +, *, / и скобки (). Используя работу со стеками найти значение каждого выражения
// и записать в файл результатов. Если в исходном файле в строке есть ошибка – найти ее предполагаемую
// позицию (позицию первой ошибки) и в выходной файл записать сообщение «Ошибка в позиции N»


#include <stdio.h>
#include <stdlib.h>
#include "validators.h"
#include "stack.h"
#include "textStack.h"
#include "RPNalg.h"
#include "util.h"
#include "txtReaderWriter.h"
#include "Errors.h"

int sumStack(Stack * stack) {
    Node* temp = stack->Head;
    int maxVal = temp->Val;

    while (temp) {
        if (temp->Val > maxVal) {
            maxVal = temp->Val;
        }
        temp = temp->Prev;
    }

    int sum = 0;
    temp = stack->Head;
    while(temp) {
        if (temp->Val == maxVal) {
            break;
        }

        sum += temp->Val;
        printf("Val summed: %d\n", temp->Val);
        temp = temp->Prev;
    }
    return sum;
}

Stack* mergeStacks(Stack* s1, Stack* s2) {
    Node* currNodeS1 = s1->Head;
    Node* currNodeS2 = s2->Head;

    Stack* mergedStack = malloc(sizeof(Stack));
    if (!mergedStack) {
        perror("Failed to allocate memory for merged stack");
        exit(EXIT_FAILURE);
    }
    mergedStack->Head = NULL;
    mergedStack->Len = 0;
    mergedStack->MaxLen = s1->Len + s2->Len;

    Stack* tempStack = malloc(sizeof(Stack));
    if (!tempStack) {
        perror("Failed to allocate memory for temp stack");
        exit(EXIT_FAILURE);
    }
    tempStack->Head = NULL;
    tempStack->Len = 0;
    tempStack->MaxLen = mergedStack->MaxLen;

    while (currNodeS1 && currNodeS2) {
        if (currNodeS1->Val <= currNodeS2->Val) {
            Push(currNodeS1->Val, tempStack);
            currNodeS1 = currNodeS1->Prev;
        } else {
            Push(currNodeS2->Val, tempStack);
            currNodeS2 = currNodeS2->Prev;
        }
    }

    while (currNodeS1) {
        Push(currNodeS1->Val, tempStack);
        currNodeS1 = currNodeS1->Prev;
    }

    while (currNodeS2) {
        Push(currNodeS2->Val, tempStack);
        currNodeS2 = currNodeS2->Prev;
    }

    Node* current = tempStack->Head;
    while (current) {
        Push(current->Val, mergedStack);
        current = current->Prev;
    }

    freeStack(tempStack);
    return mergedStack;
}


int main() {
    char validChars[4] = {'0', '1', '2', '3'};
    while (1) {
        char choice = getValidatedCharInput(
            "Choose the task:\n"
            " 1 - Element sum,\n"
            " 2 - Merge stacks,\n"
            " 3 - RPN,\n"
            " 0 - exit\n ",
            validChars, 4);


        switch (choice)
        {
        case '1':
            Stack* stack = newStack();
            FillStack(stack);
            PrintStack(stack);
            printf("Sum of stack elements = %d\n", sumStack(stack));
            freeStack(stack);
            break;
        case '2':
            Stack* stacks1 = newStack();
            FillStack(stacks1);
            Stack* stacks2 = newStack();
            FillStack(stacks2);
            Stack* mergedStack = mergeStacks(stacks1, stacks2);
            PrintStack(mergedStack);
            freeStack(stacks1);
            freeStack(stacks2);
            freeStack(mergedStack);
            break;
        case '3':
            char* exprFileName = malloc(sizeof(char)*256);
            char* resFileName = malloc(sizeof(char)*256);
            printf("Insert expressions file name: ");
            getFileName(exprFileName);
            printf("\n");
            printf("Insert res file name: ");
            getFileName(resFileName);
            FILE* fpExpr= fopen(exprFileName, "r");
            FILE* fpRes= fopen(resFileName, "w+");
            if (fpExpr == NULL || fpRes == NULL) {
                printf("Error occured when opening file\n");
                free(resFileName);
                free(exprFileName);
                return 1;
            }
            char line[1024];
            char * postfixStr = malloc(sizeof(char) * 1024);
            int currLine = 0;
            while(readLine(fpExpr, line)) {
                currLine++;
                errorsList* errors = convertInfixToPostfix(line, postfixStr, currLine);
                if (isErrors(errors)) {
                    printErrors(errors);
                    continue;
                }
                float t = calcWithRPN(postfixStr);
                fprintf(fpRes, "%f\n", t);
            }
            free(postfixStr);
            free(resFileName);
            free(exprFileName);
            fclose(fpExpr);
            fclose(fpRes);
            break;
        case '0': {
            printf("Exiting program...\n");
            return 0;
        }
        default:
            printf("Error: incorect choice");
            break;
        }
    }
}