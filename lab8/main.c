#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>
#include "funcs.h"


int main()
{
	char* filename = malloc(255);
	getValidFilename(filename, 255);
	FILE* file = fopen(filename, "w+b");
	validFileInput(file);
	countMultiplesOf(file);


	printf("\n\nBefore shift:\n");
	printFileContent(file);



	fileShift(file);

	printf("\n\nAfter shift:\n");
	printFileContent(file);

	repeatReplace(file);
	printFileContent(file);

	fclose(file);
	return 0;
}