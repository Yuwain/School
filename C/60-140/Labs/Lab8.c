#include <stdio.h>

void ReadData(int[3][6], int, int);
void RowCalc(int[3][6], int, int);
void ColumnCalc(int[3][6], int, int);

void main()
{
	const int row = 3, col = 6;
	int score[row][col], r,c;

	ReadData(score, row, col);

	printf("\n");

	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
		{
			printf("%d ", score[r][c]);
		}

		printf("\n");
	}

	printf("\n");

	RowCalc(score, row, col);
	ColumnCalc(score, row, col);

}

void ReadData(int score[3][6], int row, int col)
{
	int r, c;
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
		{
			scanf("%d", &score[r][c]);
		}
	}
}

void RowCalc(int score[3][6], int row, int col)
{
	int r, c, n, min[3] = {0};
	float avg[3] = {0}, tot[3] = {0};

	for (c = 0; c < col; c++)
	{
		for (r = 0; r < row; r++)
		{
			tot[r] += score[r][c];
			avg[r] = tot[r]/col;

			if (c == 0)
			{
				min[r] = score[r][c];
			}

			if (min[r] > score[r][c])
			{
				min[r] = score[r][c];
			}
		}
	}

	for (n = 0; n < row; n++)
	{
		printf("Row %d total, average, and minimum = %.0f, %.1f, %d\n", n + 1, tot[n], avg[n], min[n]);
	}
	printf("\n");
}

void ColumnCalc(int score[3][6], int row, int col)
{
	int r, c, n, min[6] = {0};
	float avg[6] = {0}, tot[6] = {0};


	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
		{
			tot[c] += score[r][c];
			avg[c] = tot[c]/row;
			
			if (r == 0)
			{
				min[c] = score[r][c];
			}

			if (min[c] >= score[r][c])
			{
				min[c] = score[r][c];
			}
		}
	}

	for (n = 0; n < col; n++)
	{
		printf("Column %d total, average, and minimum = %.0f, %.1f, %d\n", n + 1, tot[n], avg[n], min[n]);
	}
}
