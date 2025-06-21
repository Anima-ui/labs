#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "util.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("You have to specify file name");
        return 1;
    }

	FILE* file = fopen(argv[1], "wb+");

	fillFileWithNums(file);
    fflush(file);
    rewind(file);
	printFileContentt(file);

    printf("\nAVG = %.2lf", findAvgFromFile(file));

    swapFirstLast(file);
    fflush(file);
    rewind(file);
    printFileContentt(file);

    fclose(file);
	return 0;
}