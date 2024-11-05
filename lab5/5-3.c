#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

typedef struct matrix_size {
	size_t size_cols;
	size_t size_rows;
}*ptr_str;

void memory_clear(double** array,  size_t rows)
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

void array_manual_output(double** array, size_t rows,  size_t cols)
{
	if (array != NULL)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				printf("input element[%d][%d]: ", i + 1, j + 1);
				if (!scanf_s("%lf", &array[i][j]))
				{
					while (getchar() != '\n');
					system("cls");
					printf("are you sure about that?\n");
					j--;
					continue;
				}
			}
		}
		array_output(array, rows, cols);
	}
}

int negative_cols_search(double** array, size_t cols, size_t rows)
{
	if (array != NULL)
	{
		int search = 0;
		for (int column = 0; column < cols; column++)
		{
			for (int j = 0; j < rows; j++)
			{
				if (array[j][column] < 0)
				{
					search++;
				}
			}
			if (search == rows)
			{
				return column;
			}
			else search = 0;
		}
		return -1;
	}
}



bool cols_deleat(double*** array, size_t cols, size_t rows)
{
	if (array != NULL)
	{
		int deleated_cols_count = 0;
		for (int k = 0; k < cols; k++)
		{
			int column = negative_cols_search(*array, cols, rows);
			if (column != -1)
			{
				deleated_cols_count++;
				for (int k = 0; k < rows; k++)
				{
					for (int j = column; j < cols; j++)
					{
						(*array)[k][j] = (*array)[k][j + 1];
					}
				}
				for (int i = 0; i < rows; i++)
				{
					if (cols - deleated_cols_count > 0)
					{
						double* temp = realloc((*array)[i], sizeof(double) * (cols - deleated_cols_count));
						if (temp != NULL)
							(*array)[i] = temp;
					}
				}
			}
		}
		array_output(*array, rows, cols - deleated_cols_count);
		if (deleated_cols_count == cols)
			return false;
	}
}

int main()
{
	do 
	{
		struct matrix_size a;
		ptr_str ptr_str = &a;
		printf("press R for random or M for manual: ");
		char press_button = getchar();
		while (getchar() != '\n');
		if (press_button != 'r' && press_button != 'R' && press_button != 'm' && press_button != 'M')
		{
			printf("Invalid value\npress any symbol to continue or ` to end\n");
			continue;
		}
		printf("\ninput number of rows: ");
		if (!scanf_s("%zu", &(ptr_str->size_rows)))
		{
			while (getchar() != '\n');
			system("cls");
			printf("*_*\nTry again");
			printf("\npress any symbol to continue or ` to end\n");
			continue;
		}
		printf("input number of cols: ");
		if (!scanf_s("%zu", &(ptr_str->size_cols)))
		{
			while (getchar() != '\n');
			system("cls");
			printf("*_*\nTry again");
			printf("\npress any symbol to continue or ` to end\n");
			continue;
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
		if (press_button == 'r' || press_button == 'R')
		{
			array_random_output(array, ptr_str->size_rows, ptr_str->size_cols);
		}
		else if (press_button == 'm' || press_button == 'M')
		{
			array_manual_output(array, ptr_str->size_rows, ptr_str->size_cols);
		}
		if (cols_deleat(&array, ptr_str->size_cols, ptr_str->size_rows))
			memory_clear(array, ptr_str->size_rows);
		printf("\n\n\t\t\t\t\t\tpress ` to end\n");
	} while (_getch() != '`');

	//d1array();

	//pampam();
	return 0;
}