//Jeremy High - 103306452
//Assignment 1
//Section 51

#include <stdio.h>

//Function Prototypes
void RectangleArray(int, float, float, float, float, float[][4]);
void Coordinates(int, float, float, float[][2]);
void CheckPoints(int, int, float[][4], float[][2]);

void main()
{
	int n, t;
	char stop = ' ';
	char junk;
	float rect_arrays[10][4] = {0}; 
	float coordinates[10][2] = {0};
	float x, y, leftx, lefty, rightx, righty;

	for (n = 0; n <= 9; n++)
	{
		scanf("%c", &stop);
		scanf("%c", &junk);

		if (junk == '*')
		{
			break;
		}

		scanf("%f %f %f %f", &leftx, &lefty, &rightx, &righty);

		RectangleArray(n, leftx, lefty, rightx, righty, rect_arrays);
	}

	for (t = 0; t <= 9; t++)
	{
		scanf("%f %f", &x, &y);

		if (x >= 9999.9 && y >= 9999.9)
		{
			break;
		}

		Coordinates(t, x, y, coordinates);
	}

	CheckPoints(n, t, rect_arrays, coordinates);
}

void RectangleArray(int n, float leftx, float lefty, float rightx, float righty, float rect_array[][4])
{
	rect_array[n][0] = leftx; 
	rect_array[n][1] = lefty;
	rect_array[n][2] = rightx;
	rect_array[n][3] = righty;
}

void Coordinates(int t, float x, float y, float coordinates[][2])
{
	coordinates[t][0] = x;
	coordinates[t][1] = y;
}

void CheckPoints(int n, int t, float rect_array[][4], float coordinates[][2])
{
	int a, b, count;
	int check[t][n];

	for (a = 0; a < t; a++)
	{
		for (b = 0; b < n; b++)
		{
			if (coordinates[a][0] <= rect_array[b][0] || coordinates[a][0] >= rect_array[b][2])
			{
				check[a][b] = 0;
			}
			else if (coordinates[a][1] <= rect_array[b][3] || coordinates[a][1] >= rect_array[b][1])
			{
				check[a][b] = 0;
			}
			else
			{
				check[a][b] = 1;
			}
		}
	}

	for (a = 0; a < t; a++)
	{
		count = 0;		

		for (b = 0; b < n; b++)
		{
			if (check[a][b])
			{
				printf("Point %d is contained in figure %d\n", a+1, b+1);
			}
			else
			{
				count++;
			}
		}
	
		if (count == n)
		{
			printf("Point %d is not contained in any figure\n", a+1);
		}
	}
}
