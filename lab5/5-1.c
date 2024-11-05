#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void output(double* array, size_t size)
{
	printf("\n");
	if (array != NULL)
		for (int i = 0; i < size; i++)
			printf("%.0lf ", array[i]);
}

void manual(double* array, size_t size)
{
	if (array != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			printf("input the element %d: ", i + 1);
			if (!scanf_s("%lf", &array[i]))
			{
				while (getchar() != '\n');
				system("cls");
				printf("*_*\nTry again\n");
				i--;
				continue;
			}
		}
		output(array, size);
	}
}

void to_power(double* array, size_t size)
{
	if (array != NULL)
	{
		int index = 0;
		double* power_array = malloc(sizeof(double) * 2 * size);
		if (power_array != NULL)
		{
			for (int i = 0; i < size; i++)
			{
				power_array[index] = array[i]; // при помощи индекса указывается какому элементу нового массива присвоить какие значения
				power_array[index + 1] = array[i] * array[i];
				index += 2;
			}
			output(power_array, size * 2);
		}
		free(power_array);
	}
}

int d1array()
{
	do
	{
		size_t array_size;
		printf("input the number of elements of array: ");
		if (!scanf_s("%zu", &array_size))
		{
			while (getchar() != '\n');
			system("cls");
			printf("*_*\nTry again");
			printf("\npress any symbol to continue or ` to end\n");
			continue;
		}
		double* array = malloc(sizeof(double) * array_size);
		manual(array, array_size);
		to_power(array, array_size);
		free(array);
	} while (_getch() != '`');
	return 0;
}