#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>

int getline2(char** string, size_t* size, FILE* stream)
{
	int position = 0;
	int symbol = 0;
	if (*size == 0 || *string == NULL)
	{
		*size = 10;
		*string = malloc(*size);
		if (*string == NULL) return -1;
	}
	while ((symbol = fgetc(stream)) != EOF && symbol != '\n')
	{
		if (position + 1 >= *size)
		{
			*size *= 2;
			char* temp_ptr = realloc(*string, *size);
			if (temp_ptr == NULL) return -1;
			*string = temp_ptr;
		}
		(*string)[position++] = (char)symbol;
	}
	if (position == 0 && symbol == EOF) return -1;
	(*string)[position] = '\0';
	return position;
}


bool check(const char* string, const char* subString)
{
	int stringLen = 0, subStringLen = 0;
	while (string[stringLen] != '\0') ++stringLen;
	while (subString[subStringLen] != '\0') ++subStringLen;
	if (subStringLen > stringLen) 
	{
		printf("False\n");
		return false;
	}
	for (int i = 0; i <= stringLen - subStringLen; ++i)
	{
		bool is_match = true;
		for (int j = 0; j < subStringLen; ++j) 
		{
			if (string[i + j] != subString[j]) 
			{
				is_match = false;
				break;
			}
		}
		if (is_match) 
		{
			printf("True\n");
			return true;
		}
	}

	printf("False\n");
	return false;
}

int zadan2()
{
	char* string = NULL;
	size_t string_len = 10;
	printf("input string: ");
	getline2(&string, &string_len, stdin);
	char* subString = NULL;
	size_t subString_len = 10;
	printf("input substring: ");
	getline2(&subString, &subString_len, stdin);
	check(string, subString);
	free(string);
	free(subString);
	return 0;
}