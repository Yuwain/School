//Jeremy High - 103306452
//Lab Exam 2
//03-60-141-51

//Inclusions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Definitions
#define ROWS 10
#define COLS 10

//Function Prototypes
void ParseCommands(char [][COLS], char []);
void PrintArray(char [][COLS]); 
void Init(char [][COLS]);

void main()
{
	char A[ROWS][COLS];
	char S[100];

	gets(S);
	Init(A);
	ParseCommands(A, S);
	PrintArray(A);
}

//Takes a row of letters followed by numbers and put the number of letters into A
//Input: Empty char array A, row of letters and numbers S
//Output: A with number of letters in S in it
void ParseCommands(char A[][COLS], char S[])
{
	int a, b = 0, c = 0, d = 0;
	char *temp, hold[100];

	temp = strtok(S, " ");

	while (strcmp(temp, "0") != 0)
	{
		c = b;

		//Checks character before number and stores it in 1D array hold
		if (*temp == 'x')
		{
			*temp++;
			a = atoi(temp);

			for (b; b < c + a; b++)
				hold[b] = 'x';
		}
		else if (*temp == '-')
		{
			*temp++;
			a = atoi(temp);

			for (b; b < c + a; b++)
				hold[b] = '-';
		}

		temp = strtok(NULL, " ");
	}

	//Puts all characters in 1D array hold into 2D array A
	for (b = 0; b < ROWS; b++)
		for (c = 0; c < COLS; c++)
		{
			A[b][c] = hold[d];
			d++;
		}
}

//Prints the array of characters
//Input: Array of characters A
//Output: Printed array A
void PrintArray(char A[][COLS])
{
	int a, b;

	for (a = 0; a < ROWS; a++)
	{
		for (b = 0; b < COLS; b++)
		{
			printf("%c", A[a][b]);
		}

		printf("\n");
	}
}

//Initializes all rows in A to \0
//Made because I was getting tired of seeing gibberish when testing with fewer than 100 letters
//Input: Array A
//Output: Array A with all rows set to \0
void Init(char A[][COLS])
{
	int i;

	for (i = 0; i < ROWS; i++)
		strcpy(A[i], "\0");
}
