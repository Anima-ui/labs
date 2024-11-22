#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

void output(double* array, size_t array_size)
{
	printf("\n\n");
	for (int i = 0; i < array_size; i++)
	{
		printf("%.0lf  ", array[i]);
	}
}

void random_input(double* array, size_t array_size)
{
	srand(time(NULL));
	for (int i = 0; i < array_size; i++)
	{
		array[i] = rand() % 15;
	}
	output(array, array_size);
}

void manual_input(double* array, size_t array_size)
{
	printf("\n");
	for (int i = 0; i < array_size; i++)
	{
		printf("input the %d element: ", i + 1);
		if (!scanf_s("%lf", &array[i]))
		{
			while (getchar() != '\n');
			i -= 1;
			continue;
		}
	}
	output(array, array_size);
}

void swap(double* first, double* second)
{
	double temp = *first;
	*first = *second;
	*second = temp;
}

void quicksort(double* array, int low, int up)
{
	int pivot = array[(low + up) / 2];
	int i = low;
	int j = up;
	while (i <= j)
	{
		while (array[i] < pivot) i++;
		while (array[j] > pivot) j--;
		if (i <= j)
		{
			swap(&array[i], &array[j]);
			i++;
			j--;
		}
	}
	if (low < j)
		quicksort(array, low, j);
	if (i < up)
		quicksort(array, i, up);
}

int zadan1()
{
	size_t array_size;
	while(1)
	{
		printf("input the array size: ");
		if (!scanf_s("%zu", &array_size))
		{
			while (getchar() != '\n');
			system("cls");
			continue;
		}
		break;
	}
	double* array = malloc(sizeof(double) * array_size);
	while(1)
	{
		printf("press R for random or M for manual ");
		char key = _getch();
		if (key == 'r' || key == 'R')
		{
			random_input(array, array_size);
			break;
		}
		else if (key == 'm' || key == 'M')
		{
			manual_input(array, array_size);
			break;
		}
		else
		{
			system("cls");
			continue;
		}
	}
	quicksort(array, 0, array_size - 1);
	output(array, array_size);
	return 0;
}