#ifndef VALIDATORS_H
#define VALIDATORS_H
#include <stdbool.h>
int getValidatedIntInput(const char *message);
char getValidatedCharInput(const char *message, char validChars[], int validCharsLength);
bool isValidDouble(const char* str);
double getValidDoubleInput(const char* message);
#endif