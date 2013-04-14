//Jeremy High - 103306452
//Section 51
//Lab 3

//Inclusions
#include <stdio.h>
#include <stdlib.h>

//Definitions
#define M 10
#define N 5

//Function prototypes
void InitializeArray(int[][N]);
void PopulateRandomValues(int[][N]);
void Sort(int[][N]);
void LinearSearch(int[][N]);
void LeftShift(int [][N]);
void PrintArray(int[][N]);

void main()
{
	int a, b, select; 
	int loop = 1;
	int sort[M][N];

	//Interactive menu for choosing which function to use
	while (loop)
	{
		printf("Please select a function\n"
		       "1 - InitializeArray\n"
		       "2 - PopulateRandom\n"
		       "3 - Sort\n"
		       "4 - LinearSearch\n"
		       "5 - LeftShift\n"
		       "6 - PrintArray\n"
		       "0 - Quit\n");
		scanf("%d", &select);

		switch (select)
		{
			case 0:  loop = 0;
				 break;
			case 1:  InitializeArray(sort);
				 break;
			case 2:  PopulateRandomValues(sort);
				 break;
			case 3:	 Sort(sort);
				 break;
			case 4:  LinearSearch(sort);
				 break;
			case 5:	 LeftShift(sort);
				 break;
			case 6:  PrintArray(sort);
				 break;
			default: printf("Invalid selection\n");
		}
	}

	printf("End of program\n");
}

/*Initializes array to 0
  Input: Array of integers
  Output: Array with all values 0*/ 
void InitializeArray(int sort[][N])
{
	int a, b;

	//Initialize array to 0
	for (a = 0; a < M; a++)
		for (b = 0; b < N; b++)
			sort[a][b] = 0;
			
	PrintArray(sort);
}

/*Prints array
  Input: Integer array
  Output: Printed array*/
void PrintArray(int sort[][N])
{
	int a, b;

	//Prints array
	for (a = 0; a < M; a++)
	{
		for (b = 0; b < N; b++)
			printf("%02d ", sort[a][b]);

		printf("\n");
	}

	printf("\n");
}

/*Changes values in array to random numbers from 1 to 100
  Input: Array of integers
  Output: Array with random values from 1 to 100*/
void PopulateRandomValues(int sort[][N])
{
	int a, b;

	//Puts random numbers from 1 to 100 in array
	for (a = 0; a < M; a++)
		for (b = 0; b < N; b++)
			sort[a][b] = rand() % 100 + 1;

	PrintArray(sort);
}

/*Searches array for a certain number
  Input: Integer array
  Output: Whether or not number is in array*/
void LinearSearch(int sort[][N])
{
	int a, b, n;
	int found = 0;

	printf("What number from 1 to 100 would you like to look for? ");
	scanf("%d", &n);

	//Search for input number
	for (a = 0; a < M; a++)
		for (b = 0; b < N; b++)
			if (sort[a][b] == n)
				found = 1;

	//Whether number is found or not, say so
	if (found)
		printf("%d is found in array\n", n);
	else
		printf("%d is not found in array\n", n);	

	printf("\n");
}

/*Sorts array from lowest to highest
  Input: Array of integers
  Output: Array sorted from lowest to highest*/
void Sort(int sort[][N])
{
	int a, b, loop = 1;
	int temp, count;

	//Loop while not completely sorted
	while (loop)
	{
		loop = 0;

		for (a = 0; a < M; a++)
		{
			for (b = 0; b < N-1; b++)
			{
				//For the first row
				if (a == 0)
				{
					//If first number is higher than second, swap them
					if (sort[a][b] > sort[a][b+1])
					{
						temp = sort[a][b];
						sort[a][b] = sort[a][b+1];
						sort[a][b+1] = temp;
						loop = 1;
					}
				}

				//For every other row
				else
				{
					//For the first column
					if (b == 0)				
					{
						//If number is less than number in previous row's last column, swap them
						if (sort[a][b] < sort[a-1][N-1])
						{
							temp = sort[a-1][N-1];
							sort[a-1][N-1] = sort[a][b];	
							sort[a][b] = temp;
							loop = 1;
						}
					}
					
					//If first number is higher than second, swap them
					if (sort[a][b] > sort[a][b+1])
					{
						temp = sort[a][b];
						sort[a][b] = sort[a][b+1];
						sort[a][b+1] = temp;
						loop = 1;
					}
				}
			}
		}
	}

	PrintArray(sort);
}

/*Shifts all number in array to the left
  Input: Array of integers
  Output: Array of integers with all numbers moved one space left*/
void LeftShift(int sort[][N])
{
	int a, b;
	int new[M][N];

	//Puts sorted array into new array with everything shifted left
	for (a = 0; a < M; a++)
	{
		for (b = 0; b < N; b++)
		{
			if (b == N-1)
			{
				if (a == M-1)
					new[a][b] = sort[0][0];
				else
					new[a][b] = sort[a+1][0];
			}
			else
			{
				new[a][b] = sort[a][b+1];
			}
		}
	}

	//Puts everything back into first array for consistency in main
	for (a = 0; a < M; a++)
		for (b = 0; b < N; b++)
			sort[a][b] = new[a][b];

	PrintArray(sort);
}
