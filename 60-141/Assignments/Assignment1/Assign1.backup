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
	char junk;
	char stop = ' ';
	float rect_arrays[10][4] = {0}; 
	float coordinates[10][2] = {0};
	float x, y, leftx, lefty, rightx, righty;

	//Takes coordinates for corners of rectangle and sends them to RectangleArray
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

	//Gets points used to check location of and sends them to Coordinates
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

//Puts coordinates for rectangle corners in an array
//Input: Row number n, x & y coordinates for corners, array of floats
//Output: Array with x & y values for rectangle corners in row n
void RectangleArray(int n, float leftx, float lefty, float rightx, float righty, float rect_array[][4])
{
	rect_array[n][0] = leftx; 
	rect_array[n][1] = lefty;
	rect_array[n][2] = rightx;
	rect_array[n][3] = righty;
}

//Puts point to check in an array
//Input: Row number t, coordinates for point to check, array of floats
//Output: Array with x & y values for point in row t
void Coordinates(int t, float x, float y, float coordinates[][2])
{
	coordinates[t][0] = x;
	coordinates[t][1] = y;
}

//Checks points against rectangle coordinates
//Input: Amount of rows n and t, array of rectangles, array of points
//Output: Whether or not checked point is contained in a rectangle
void CheckPoints(int n, int t, float rect_array[][4], float coordinates[][2])
{
	int a, b, count;
	int check[t][n];

	//Checks if point is in rectangle and puts value of 1 in check array if it is
	for (a = 0; a < t; a++)
	{
		for (b = 0; b < n; b++)
		{
			//If point is outside x coordinates of rectangle, put value of 0 in check array
			if (coordinates[a][0] <= rect_array[b][0] || coordinates[a][0] >= rect_array[b][2])
			{
				check[a][b] = 0;
			}

			//If point is outside y coordinates of rectangle, put value of 0 in check array
			else if (coordinates[a][1] <= rect_array[b][3] || coordinates[a][1] >= rect_array[b][1])
			{
				check[a][b] = 0;
			}

			//If point is between both x and y coordinates of rectangle, put value of 1 in check array
			else
			{
				check[a][b] = 1;
			}
		}
	}

	//Searches check array for values of 1 to determine which rectangle/s point is contained in
	for (a = 0; a < t; a++)
	{
		count = 0;		

		for (b = 0; b < n; b++)
		{
			//If 1 is found, print for which point and rectangle it's found
			if (check[a][b])
			{
				printf("Point %d is contained in figure %d\n", a+1, b+1);
			}

			//If 0 is found, add to counter
			else
			{
				count++;
			}
		}
	
		//If count is the same as the amount of rectangles, point is not in any rectangle
		if (count == n)
		{
			printf("Point %d is not contained in any figure\n", a+1);
		}
	}
}
