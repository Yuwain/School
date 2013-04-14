#include <stdio.h>

int ReadArray(float [][6], int);
void RowCalc(float [][6], int [], float [], int);
void ColumnCalc(float [][6], int [], float [], int);

void main()
{
	int A = 0, r, c, row, minR[12] = {0}, minC[6] = {0};
	float avgR[12] = {0}, avgC[6] = {0}, score[12][6] = {0};

	row = ReadArray(score, row);
	
	RowCalc(score, minR, avgR, row);
	ColumnCalc(score, minC, avgC, row);

	for (c = 0; c < 4; c++)
	{
		avgC[4] += avgC[c];
		
		if (c == 0)
		{
			minC[5] = minC[c];
		}
	
		if (minC[5] > minC[c])
		{
			minC[5] = minC[c];
		}
	}

	avgC[4] = avgC[4]/c;

	for (r = 0; r < row+2; r++)
	{
		for (c = 4; c < 6; c++)
		{
			if (c == 4)
			{
				score[r][c] = avgR[r];
			}
			else
			{
				score[r][c] = minR[r];
			}
		}

		if (r >= row)
		{
			for (c = 0; c < 6; c++)
			{
				if (r == row)
				{
					score[r][c] = avgC[c];
				}
				else
				{
					score[r][c] = minC[c];
				}
			}
		}
	}

	printf("        Test1 Test2 Test3 Test4  Avg    Min\n        ");

	for (r = 0; r < row+2; r++)
	{
		for (c = 0; c < 6; c++)
		{
			if (score[r][c] >= 90)
			{
				A++;
			}

			if (r >= row && c == 0)
			{
				if (r == row)
				{
					printf("Average ");
				}
				else
				{
					printf("Minimum ");
				}
			}

			if ((c < 4 || c == 5) && r != row)
			{
				if (score[r][c] == 0)
				{
					printf("   --");
				}
				else
				{
					printf("%5.0f ", score[r][c]);
				}
			}
			else
			{
				if (c == 5)
				{
					if (score[r][c] == 0)
					{
						printf("   --");
					}
					else
					{
						printf("%5.0f ", score[r][c]);
					}
				}
				else
				{
					if (score[r][c] == 0)
					{
						printf("----- ");
					}
					else
					{
						printf("%5.2f ", score[r][c]);
					}
				}
			}
		}

		if (r >= row-1)
		{
			if (r == row-1 || r == row)
			{
				printf("\n");
			}
			else
			{
				printf("\n\n");
			}
		}
		else
		{
			printf("\n        ");
		}
	}

	if (A == 1)
	{
		printf("There is %d score greater than or equal to 90 percent\n", A);
	}
	else
	{
		printf("There are %d scores greater than or equal to 90 percent\n", A);
	}
}

int ReadArray(float score[][6], int r)
{
	int c;

	for (r = 0; r < 10; r++)
	{
		for (c = 0; c < 4; c++)
		{
			scanf("%f", &score[r][c]);
			
			if (c == 0)
			{
				if (score[r][c] == -1)
				{
					break;
				}
			}
		}
		
		if (score[r][c] == -1)
		{
			break;
		}
	}

	return r;
}

void RowCalc(float score[][6], int min[], float avg[], int row)
{
	int r, c;

	for (r = 0; r < row; r++)
	{
		for (c = 0; c < 4; c++)
		{
			if (c == 0)
			{
				min[r] = score[r][c];
			}

			if (min[r] > score[r][c])
			{
				min[r] = score[r][c];
			}

			avg[r] += score[r][c];
		}
		
		avg[r] = avg[r]/c;
	}
}

void ColumnCalc(float score[][6], int min[], float avg[], int row)
{
	int r, c;

	for (c = 0; c < 4; c++)
	{
		for (r = 0; r < row; r++)
		{
			if (r == 0)
			{
				min[c] = score[r][c];
			}

			if (min[c] > score[r][c])
			{
				min[c] = score[r][c];
			}
	
			avg[c] += score[r][c];
		}

		avg[c] = avg[c]/r;
	}
}
