#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>


void clear(double** array, size_t size_line)
{
	if (array != NULL)
	{
		for (int i = 0; i < size_line; i++)
			free(array[i]);
		free(array);
	}
}

void array_outputt(int** array, size_t size_line)
{
	printf("\n");
	for (int i = 0; i < size_line; i++)
	{
		for (int j = 0; ;)
		{
			do{
				printf("[%d]\t", array[i][j]);
			} while (array[i][j++] != -1);
			break;
		}
		printf("\n");
	}
}

void element_deleat(int*** array, size_t size_line, unsigned int k) //k номер после которого должны быть удалены элементы
{
	for (int i = 0; i < size_line; i++)
	{
		int j = 0;
		while ((*array)[i][j] != -1)
			j++;
		int actual_line_size = j;
		if (actual_line_size > k)
		{
			(*array)[i][k] = -1;
			int* temp = realloc((*array)[i], sizeof(int) * (k + 1));
			if (temp != NULL)
				(*array)[i] = temp;
		}
	}
	printf("\n\n");
	array_outputt(*array, size_line);
}

void memory_place(size_t size_line, unsigned int k)
{
	int** array = malloc(sizeof(int*) * size_line);
	if (array != NULL)
	{
		for (int i = 0; i < size_line; i++)
		{
			array[i] = NULL;
			for (int j = 0; ; j++)
			{
				int* temp = realloc(array[i], sizeof(int) * (j + 1));
				if (temp != NULL)
					array[i] = temp;
				else
				{
					for (int k = 0; k < i; k++)
						free(array[k]);
					free(array);
					exit(EXIT_FAILURE);
				}
				printf("input the %d element of the %d line: ", j + 1, i + 1);
				if (!scanf_s("%d", &array[i][j]))
				{
					while (getchar() != '\n');
					system("cls");
					printf("weeeell\nJust try again\n");
					j--;
					continue;
				}
				if (array[i][j] == -1)
					break;
			}
		}
	}
	array_outputt(array, size_line);
	element_deleat(&array, size_line, k);
	clear(array, size_line);
}



int pampam()
{
	do
	{
		size_t size_line;
		printf("input number of lines: ");
		if (!scanf_s("%zu", &size_line))
		{
			while (getchar() != '\n');
			system("cls");
			printf("(\nTry again");
			printf("\npress any symbol to continue or ` to end\n");
			continue;
			
		}
		unsigned int k;
		printf("input k-element: ");
		if (!scanf_s("%u", &k))
		{
			while (getchar() != '\n');
			system("cls");
			printf("*_*\nTry again");
			printf("\npress any symbol to continue or ` to end\n");
			continue;
		}
		memory_place(size_line, k);
		printf("\n\n\t\t\t\t\t\tpress ` to end\n");
	} while (_getch() != '`');
	return 0;
}