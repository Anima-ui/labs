#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void addFileType(char * str) {
    int len = strlen(str);
    if (len < 4 || strncmp(str + len - 4, ".txt", 4) != 0) {
        strcat(str, ".txt");
    }
}

void getFileName(char * str) {
    fgets(str, 252, stdin);
    str[strcspn(str, "\n")] = '\0'; 
    addFileType(str);
}

char * getFileNameFromCmdArgs(int argCount, char * argVals[]) {
    char * fileName = malloc(100 * sizeof(char));
    if (argCount < 2) {
        printf("Insert file name: ");
        getFileName(fileName);
        return fileName;
    }
    fileName = argVals[1]; 
    addFileType(fileName);
    return fileName;
}