#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "funcs.h"

void getStringInput(char* str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
    if (strlen(str) == size - 1) {
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

void getValidFilename(char* filename, size_t size)
{
    const char forbidden_chars[] = "<>:\"/\\|?*";

    while (1)
    {
        printf("Input file name: ");
        if (!fgets(filename, size, stdin)) 
        {
            printf("Error!\n");
            continue;
        }

        size_t len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n')
        {
            filename[len - 1] = '\0';
            len--;
        }

        if (len == 0)
        {
            printf("File name cant be empty!\n");
            continue;
        }

        int valid = 1;
        for (size_t i = 0; i < len; i++)
        {
            if (strchr(forbidden_chars, filename[i]))
            {
                printf("Error: file name cant contain forbidden symbols\n");
                valid = 0;
                break;
            }
        }

        if (valid)
            break; 
    }
}

void validFileInput(FILE* file)
{
    char input[1024];

    printf("Input nat numbers separated by a space: ");
    if (!fgets(input, 1024, stdin))
    {
        printf("Error!\n");
        return;
    }

    input[strcspn(input, "\n")] = '\0';

    char* context = NULL;
    char* token = strtok_s(input, " ", &context);
    while (token)
    {
        bool valid = true;
        for (int i = 0; token[i] != '\0'; ++i)
        {
            if (!isdigit(token[i]))
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            int number = atoi(token);
            if (number > 0)
                fwrite(&number, sizeof(int), 1, file);
            else
                printf("Skipped: %s(not a natural number)\n", token);
        }
        else
        {
            printf("Skipped: %s(not a number)\n", token);
        }
        token = strtok_s(NULL, " ", &context);
    }
}

void countMultiplesOf(FILE* file)
{
    int divisor = someValidIntInput("Input divisor: ");

    int count = 0;
    int number;
    rewind(file);

    while (fread(&number, sizeof(int), 1, file) == 1)
    {
        if (number % divisor == 0) 
            count++;
    }

    printf("Count = %d", count);
}


void fileShift(FILE* file)
{
    int k = someValidIntInput("\nInput k: ");

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    int count = fileSize / sizeof(int);

    if (count == 0 || k % count == 0) 
        return;

    k = k % count; 

    int* numbers = malloc(fileSize);

    rewind(file);
    fread(numbers, sizeof(int), count, file);

    for (int i = 0; i < k; i++)
    {
        int temp = numbers[count - 1];
        for (int j = count - 1; j > 0; j--)
        {
            numbers[j] = numbers[j - 1];
        }
        numbers[0] = temp;
    }

    rewind(file);
    fwrite(numbers, sizeof(int), count, file);

    free(numbers);
}



int someValidIntInput(const char* str)
{
    int number;
    while (1)
    {
        printf("%s", str);
        if (scanf_s("%d", &number) != 1)
        {
            while (getchar() != '\n');
            printf("Invalid input\n");
            continue;
        }
        break;
    }
    return number;
}

void printFileContent(FILE* file)
{
    fseek(file, 0, SEEK_END);
    int count = ftell(file) / sizeof(int);

    int number;
    rewind(file);

    printf("File content:\n");
    for (int i = 0; i < count; i++)
    {
        fread(&number, sizeof(int), 1, file);
        printf("%d ", number);
    }
    printf("\n");
}

void repeatReplace(FILE* file)
{

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    int count = fileSize / sizeof(int);

    int* numbers = malloc(fileSize);
    rewind(file);
    fread(numbers, sizeof(int), count, file);

    for (int i = 0; i < count; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (numbers[i] == numbers[j])
                numbers[j] = 0;
        }
    }

    rewind(file);
    fwrite(numbers, sizeof(int), count, file);

    free(numbers);
}

void addFileType(char* str) {
    int len = strlen(str);
    if (len < 4 || strncmp(str + len - 4, ".txt", 4) != 0) {
        strcat(str, ".txt");
    }
}

void getFileName(char* str) {
    fgets(str, 252, stdin);
    str[strcspn(str, "\n")] = '\0';
    addFileType(str);
}

char* getFileNameFromCmdArgs(int argCount, char* argVals[]) {
    char* fileName = malloc(100 * sizeof(char));
    if (argCount < 2) {
        printf("Insert file name: ");
        getFileName(fileName);
        return fileName;
    }
    fileName = argVals[1];
    addFileType(fileName);
    return fileName;
}

int getValidatedIntInput(const char* message)
{
    while (1)
    {
        printf("%s", message);
        int input = 0;
        char a;
        int isAnyErrorsInInput = 0;
        int valueLen = 0;
        short sign = 1;
        int rawBufferLen = 0;
        while ((a = getchar()) != '\n')
        {
            rawBufferLen++;
            if (valueLen == 0 && a == '-')
            {
                sign = -1;
                valueLen++;
                continue;
            }
            if (a < '0' || a > '9')
            {
                isAnyErrorsInInput = 1;
                break;
            }
            else
            {
                if (sign == 1 && input > (INT_MAX - '0') / 10) {
                    isAnyErrorsInInput = 1;
                    break;
                }
                if (sign == -1 && input < (INT_MIN + '0') / 10) {
                    isAnyErrorsInInput = 1;
                    break;
                }
                valueLen++;
                input = input * 10 + (a - '0');
            }
        }
        if (sign == -1 && valueLen == 1)
        {
            isAnyErrorsInInput = 1;
            rawBufferLen--;
        }
        if (!isAnyErrorsInInput && valueLen)
        {
            return input * sign;
        }
        else {
            input = 0;
            printf("Incorrect input \n");
        }
        if (rawBufferLen > 0 && isAnyErrorsInInput)
        {
            while ((getchar()) != '\n');
        }
    }
}

char getValidatedCharInput(const char *message, char validChars[], int validCharsLength)
{
    if(validCharsLength < 2) return 'M';
    char input;
    while (1) 
    {
        printf("%s", message);
        if (scanf(" %c", &input) == 1) 
        {
            input = toupper(input);  
            for (int i = 0; i < validCharsLength; i++) 
            {
                if (input == toupper(validChars[i])) 
                {
                    while (getchar() != '\n');
                    return input;
                }
            }
        }
        printf("Invalid input. Please enter one of the following characters: ");
        for (int i = 0; i < validCharsLength; i++) 
        {
            printf("%c ", validChars[i]);
        }
        printf("\n");
        while (getchar() != '\n');  
    }
}
