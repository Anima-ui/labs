#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>


void out(double matrix[20][20], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.0lf\t", matrix[i][j]);
		}
		printf("\n");
	}
}

double summa(double matrix[20][20], int size)
{
	int mid_line = size / 2;
	double sum = 0;
	for (int i = mid_line; i < size; i++)
	{
		for (int j = size - i - 1; j <= i; j++)
		{
			sum += matrix[i][j];
		}
	}
}




int zadan()
{
	do {
		double matrix[20][20];
		int n;
		printf("input the number of colmns and lines(< 20 please): ");
		if (!scanf_s("%d", &n) || n > 20)
		{

			while (getchar() != '\n');
			system("cls");
			printf("no");
			printf("\npress any symbol to continue or ` to end\n");
			continue;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = rand() % 10;
			}
		}
		if (n < 3)
		{
			printf("there is such area\n");
			printf("\npress any symbol to continue or ` to end\n");
			continue;
		}
		out(matrix, n);
		double sum = summa(matrix, n);
		printf("\n%lf", sum);
		printf("\n\n\t\t\t\t\t\tpress ` to end\n");
	} while (_getch() != '`');
	return 0;
}