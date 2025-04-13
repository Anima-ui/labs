#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>


int getline(char** string, size_t* size, FILE* stream)
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


int repeat_search(char* string, char* word)
{
	int count = 0;
	int i = 0, j;
	int is_match;

	int word_len = 0;
	while (word[word_len] != '\0') word_len++;
	while (string[i] != '\0') 
	{
		is_match = 1; 
		for (j = 0; j < word_len; j++) 
		{
			if (string[i + j] == '\0' || string[i + j] != word[j]) 
			{
				is_match = 0; 
				break;
			}
		}
		if (is_match) 
		{
			int before = (i == 0 || isspace(string[i - 1])); 
			int after = (isspace(string[i + word_len]) || string[i + word_len] == '\0'); 
			if (before && after)
			{
				count++;
			}
		}
		i++; 
	}
	return count;
}

bool is_word(char* word, int len)
{
	for (int i = 0; i < len; ++i)
	{
		if (isspace(word[i]))
			return false;
	}
	return true;
}

int zadan1()
{
	char* string = NULL;
	size_t string_len = 0;
	printf("input the string: ");
	int check = getline(&string, &string_len, stdin);
	if (check != -1)
	{
		size_t word_len = 100;
		char* word = malloc(word_len + 1);
		printf("\nsize=%d\n", check);
		if (word != NULL)
		{
			printf("input the word: ");
			getline(&word, &word_len, stdin);
			int len = 0;
			while (word[len] != '\0') len++;
			if (is_word(word, len))
			{
				if (word[len - 1] == '\n') word[len - 1] = '\0';
				int result = repeat_search(string, word);
				printf("\n\n\nword count = %d", result);
			}
			else
				printf("not a word\n");
		}
		free(word);
	}
	free(string);
	return 0;
}