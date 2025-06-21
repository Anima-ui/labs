#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void printFileContentt(FILE* fp) {
    int num;
    rewind(fp); 
    printf("\nFile content:\n");
    while (fread(&num, sizeof(int), 1, fp) == 1) {
        printf("%d ", num);
    }
    printf("\n");
}

void fillFileWithNums(FILE* file) {
    printf("Enter natural numbers (end with -1)\n");
    int num;
    while (1) {
        num = someValidIntInput("Insert integer value: ");
        if (num == -1) {
            break;
        }
        fwrite(&num, sizeof(int), 1, file); 
    }
}

double findAvgFromFile(FILE* fp) {
    int num;
    int count = 0;
    double sum = 0.0;

    rewind(fp); 
    while (fread(&num, sizeof(int), 1, fp) == 1) {
        sum += num;
        count++;
    }

    if (count == 0) return 0.0; 
    return sum / count;
}

void swapFirstLast(FILE* fp) {
    int first, last;

    rewind(fp);
    if (fread(&first, sizeof(int), 1, fp) != 1) return; 
    fseek(fp, -(long)sizeof(int), SEEK_END);
    if (fread(&last, sizeof(int), 1, fp) != 1) return; 

   
    fseek(fp, 0, SEEK_SET);
    fwrite(&last, sizeof(int), 1, fp);
    fseek(fp, -(long)sizeof(int), SEEK_END);
    fwrite(&first, sizeof(int), 1, fp);
}
