#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

void maxi(double matrix[6][6])
{
	double sum = 0;
	double save = matrix[0][0];
	for (int j = 0; j < 6; j++)
	{
		if (j % 2 == 1)
		{
			for (int i = 0; i < 6; i++)
				if (matrix[j][i] > save)
					save = matrix[j][i];
		}
		else
			for (int i = 0; i < 6; i++)
				if (matrix[j][i] < save)
					save = matrix[j][i];
		printf("\n\n%lf", save);
		sum += save;
	}
	printf("\n\nsum = %lf\n", sum);
}

void output(double matrix[6][6])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			printf("%.0lf\t", matrix[i][j]);
		}
		printf("\n");
	}
}


int search(double matrix[6][6])
{
	int sum = 0;
	int search = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (matrix[i][j] <= matrix[i][j + 1])
				sum++;
			if (matrix[i][j] == matrix[i][j + 1])
				search++;
		}
		if (sum == 5 && search < 5)
		{
			printf("\n\nthe first sorted line is %d\n", i + 1);
			return i;
		}
		search = 0;
		sum = 0;
	}
	return -1;
}
void upside(double matrix[6][6], int line)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			if (matrix[line][j] < matrix[line][j + 1])
			{
				double temp = matrix[line][j];
				matrix[line][j] = matrix[line][j + 1];
				matrix[line][j + 1] = temp;
			}

		}
	}
}



int main()
{
	srand(time(NULL));
	do {
		double matrix[6][6];
		char key;
		printf("press R for random or M for manual ");
		key = _getch();
		if (key == 'r' || key == 'R')
		{
			printf("\n\n");
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					matrix[i][j] = rand() % 10;
				}
			}
		}
		else if (key == 'm' || key == 'M')
		{
			printf("\n\n");
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					printf("input element [%d][%d]: ", i, j);
					if (!scanf_s("%lf", &matrix[i][j]))
					{
						while (getchar() != '\n');
						system("cls");
						printf("no");
						printf("\npress any symbol to continue or ` to end\n");
						goto continue_programm;
					}
				}
			}
		}
		else
		{
			system("cls");
			printf("invalid case\n");
			printf("\npress any symbol to continue or ` to end\n");
			continue;
		}
		output(matrix);
		maxi(matrix);
		int line = search(matrix);
		if (line != -1)
		{
			upside(matrix, line);
			output(matrix);
		}
		else
			printf("\n\nthere is no sorted line\n\n");
		printf("\n\n\t\t\t\t\t\tpress ` to end\n");
	continue_programm:;

	} while (_getch() != '`');	


	//zadan();
	return 0;
}

