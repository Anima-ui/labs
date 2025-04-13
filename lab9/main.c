#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void printFileContentt(FILE* fp) {
    printf("\n");
    fseek(fp, 0, SEEK_END);
    int numCount = ftell(fp) / sizeof(char);
    fseek(fp, 0, SEEK_SET);
    char temp;
    for (int i = 0; i < numCount; i++) {
        fread(&temp, sizeof(char), 1, fp);
        printf("%c ", temp);
    }

}

void fillFileWithNums(FILE* file) {
    printf("Enter natural numbers (end with -1)\n");
    int num;
    while (1)
    {
        num = someValidIntInput("Insert integer value: ");
        if (num == -1) {
            break;
        }
        num += '0';
        fwrite(&num, sizeof(char), 1, file);
    }
}

double findAvgFromFile(FILE* fp) {
    double avg = 0;
    fseek(fp, 0, SEEK_END);
    int numCount = ftell(fp) / sizeof(char);
    fseek(fp, 0, SEEK_SET);
    char temp;
    for (int i = 0; i < numCount; i++) {
        fread(&temp, sizeof(char), 1, fp);
        int num = temp - '0';
        avg += num;
    }
    avg /= numCount;
    return avg;
}

void swapFirstLast(FILE* fp)
{
    char temp;
    char temp1;

    fseek(fp, 0, SEEK_SET);
    fread(&temp, sizeof(char), 1, fp);
    fseek(fp, -1 * sizeof(char), SEEK_END);
    fread(&temp1, sizeof(char), 1, fp);

    fseek(fp, -1 * sizeof(char), SEEK_END);
    fwrite(&temp, sizeof(char), 1, fp);

    fseek(fp, 0, SEEK_SET);
    fwrite(&temp1, sizeof(char), 1, fp);
}


int main(int argc, char* argv[])
{
	char* filename = malloc(255);
	filename = argv[1];
	FILE* file = fopen(filename, "w+");

	fillFileWithNums(file);
	printFileContentt(file);

    printf("\nAVG = %.2lf", findAvgFromFile(file));

    swapFirstLast(file);
    printFileContentt(file);
    fclose(file);
	return 0;
}