//Jeremy High
//103306452
//60-141-51
//January 24th, 2012

#include <stdio.h>
#define ROWS    21
#define COLS    20

void Print(float [][COLS], int, int);
void AverageOfColumns(float [][COLS], int, int);
void PrintStatistics(float [][COLS], int, int);

void main()
{
	int p, q;
	int rows, cols;
	float A[ROWS][COLS];

	printf("Enter # of rows, # of cols: ");
	scanf("%d %d", &rows, &cols);

	for (p = 0; p < rows; p++)
	{
		printf("Enter %d column values for row %d:\n", cols, p + 1);
		
		for (q = 0; q < cols; q++)
		{
			scanf("%f", &A[p][q]);
		}
	}

	Print(A, rows, cols);
	AverageOfColumns(A, rows, cols);
	
	printf("\n");
	
	Print(A, rows + 1, cols);
	PrintStatistics(A, rows, cols);
}

void Print(float A[][COLS], int rows, int cols)			//prints array
{
	int a, b;

	for (a = 0; a < rows; a++)
	{
		for (b = 0; b < cols; b++)
		{
			printf("%.2f ", A[a][b]);
		}

		printf("\n");
	}
}

void AverageOfColumns(float A[][COLS], int rows, int cols)	//makes last row of array the averages of each column
{
	int a, b;
	float avg = 0;

	for (b = 0; b < cols; b++)
	{
		for (a = 0; a < rows; a++)
		{
			avg += A[a][b];
		}

		A[rows][b] = avg/rows;				//makes column b of last row the average of the rest of the column
		avg = 0;
	}
}

void PrintStatistics(float A[][COLS], int rows, int cols)	//finds and prints which columns have the largest and smallest averages
{
	int a, n = 0, m = 0;
	float max, min;

	max = A[rows][0];
	min = A[rows][0];

	for (a = 1; a < cols; a++)
	{
		if (A[rows][a] > max)				//checks highest average against next column's
		{
			max = A[rows][a];
			m = a;					//saves column number highest average was found
		}

		if (A[rows][a] < min)				//checks lowest average against next column's
		{
			min = A[rows][a];
			n = a;					//saves column number lowest average was found
		}
	}

	printf("Column %d is the largest\n"
	       "Column %d is the smallest\n", m + 1, n + 1);
}
