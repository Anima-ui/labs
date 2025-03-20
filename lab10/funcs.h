#pragma once
void getValidFilename(char* filename, size_t size);

void validFileInput(FILE* file);

void countMultiplesOf(FILE* file);

void fileShift(FILE* file);

int someValidIntInput(const char* str);

void printFileContent(FILE* file);

void repeatReplace(FILE* file);

void addFileType(char* str);
void getFileName(char* str);
char* getFileNameFromCmdArgs(int argc, char* argv[]);

int getValidatedIntInput(const char* message);

char getValidatedCharInput(const char* message, char validChars[], int validCharsLength);
