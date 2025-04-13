#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

typedef struct matrix_size {
	size_t size_cols;
	size_t size_rows;
}*ptr_str;

void memory_clear(double** array, size_t rows)
{
	if (array != NULL)
	{
		for (int i = 0; i < rows; i++)
			free(array[i]);
		free(array);
	}
}

void array_output(double** array, size_t rows, size_t cols)
{
	printf("\n");
	if (array != NULL && rows > 0 && cols > 0)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				printf("%.0lf\t", array[i][j]);
			}
			printf("\n");
		}
	}
	else printf("there is no matrix");
}

void array_random_output(double** array, size_t rows, size_t cols)
{
	if (array != NULL)
	{
		srand(time(NULL));
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				array[i][j] = rand() % 10;
			}
		}
		array_output(array, rows, cols);
	}
}

void array_manual_output(double** array, size_t rows, size_t cols)
{
	if (array != NULL)
	{
		printf("\n");
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				printf("input element[%d][%d]: ", i + 1, j + 1);
				if (!scanf_s("%lf", &array[i][j]))
				{
					while (getchar() != '\n');
					j -= 1;
					continue;
				}
			}
		}
		array_output(array, rows, cols);
	}
}

void sort(double*** matrix, size_t size_rows, size_t size_cols)
{
	int k; //выполнить сортировку строк, номер которых кратен k
	int sum_row_first = 0; // гений мысли, можно использовать массив для хранения каждой суммы и при перемещении строк перемещать соответствующие суммы
	int sum_row_second = 0;
	printf("\n");
	while(1)
	{
		printf("input k: ");
		if (!scanf_s("%d", &k) || k <= 0)
		{
			while (getchar() != '\n');
			system("cls");
			continue;
		}
		break;
	}
	for (int l = 0; l < size_rows - 1; l++)
	{
		for (int i = 0; i < size_rows - l - 1; i++)
		{
			if (i % k == 0 && i + k < size_rows)
			{
				for (int j = 0; j < size_cols; j++)
				{
					if ((*matrix)[i][j] > 0)
					{
						sum_row_first += (*matrix)[i][j];
					}
					if ((*matrix)[i + k][j] > 0)
					{
						sum_row_second += (*matrix)[i + k][j];
					}
				}
				if (sum_row_second > sum_row_first)
				{
					for (int j = 0; j < size_cols; j++)
					{
						int temp = (*matrix)[i][j];
						(*matrix)[i][j] = (*matrix)[i + k][j];
						(*matrix)[i + k][j] = temp;
					}
				}
				sum_row_first = 0;
				sum_row_second = 0;
			}
		}
	}
	array_output(*matrix, size_rows, size_cols);
}

int zadan2() 
{
	struct matrix_size a;
	ptr_str ptr_str = &a;
	while(1)
	{
		printf("input number of rows: ");
		if (!scanf_s("%zu", &(ptr_str->size_rows)))
		{
			while (getchar() != '\n');
			system("cls");
			continue;
		}
		break;
	}
	while(1)
	{
		printf("input number of cols: ");
		if (!scanf_s("%zu", &(ptr_str->size_cols)))
		{
			while (getchar() != '\n');
			system("cls");
			continue;
		}
		break;
	}
	double** array = malloc(sizeof(double*) * ptr_str->size_rows);
	if (array != NULL)
	{
		for (int i = 0; i < ptr_str->size_rows; i++)
		{
			double* temp = malloc(sizeof(double) * ptr_str->size_cols);
			if (temp != NULL)
				array[i] = temp;
		}
	}
	while(1)
	{
		printf("press R for random or M for manual: ");
		char press_button = _getch();
		if (press_button == 'r' || press_button == 'R')
		{
			array_random_output(array, ptr_str->size_rows, ptr_str->size_cols);
			break;
		}
		else if (press_button == 'm' || press_button == 'M')
		{
			array_manual_output(array, ptr_str->size_rows, ptr_str->size_cols);
			break;
		}
		else 
		{
			system("cls");
			continue;
		}
	}

	sort(&array, ptr_str->size_rows, ptr_str->size_cols);
	memory_clear(array, ptr_str->size_rows);

	//parara();
	return 0;
}