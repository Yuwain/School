//Jeremy High - 103306452
//Lab Exam 2
//03-60-141-51

//Inclusions
#include <stdio.h>
#include <string.h>

//Definitions
#define ROWS 9
#define COLS 10

//Function Prototypes
void InitializeA(char [][COLS]);
void PrintArray(char [][COLS]);
void Tokenize(char [][COLS], char []);

void main()
{
	char A[ROWS][COLS];
	char S[] = "the cat in the hat";

	InitializeA(A);
	Tokenize(A, S);
	PrintArray(A);
}

//Initialize all strings in an array to \0
//Input: An array of strings, A
//Output: Same array of strings with all strings set to \0
void InitializeA(char A[][COLS])
{
	int a, b;

	for (a = 0; a < ROWS; a++)
			strcpy(A[a], "\0");
}

//Breaks a sentence into individual words and sorts those words based on first letter
//Input: An array of strings, A, and a sentence S
//Output: Array A with words from sentence S sorted based on first letter of each word
void Tokenize(char A[][COLS], char S[])
{
	int a, b;
	char *temp;

	temp = strtok(S, " ");

	while (temp != NULL)
	{
		//Checks if word starts with a, b, or c
		if (*temp == 'a' || *temp == 'b' || *temp == 'c')
		{
			//Checks if row 0 is empty. If not, checks other rows and puts word in first empty row
			if (*A[0] == 0)
				strcpy(A[0], temp);
			else
				for (a = 1; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 10;
					}
		}

		//Checks if word starts with d, e, or f
		else if (*temp == 'd' || *temp == 'e' || *temp == 'f')
		{
			//Checks if row 1 is empty. If not, checks other rows and puts word in first empty row
			if (*A[1] == 0)
				strcpy(A[1], temp);
			else
			{
				for (a = 2; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 9;
					}
		
				if (a != 10)
					for (b = 0; b < 1; b++)
						if (*A[b] == 0)
						{
							strcpy(A[b], temp);
							b = 10;
						}
			}
		}

		//Checks if word starts with g, h, or i
		else if (*temp == 'g' || *temp == 'h' || *temp == 'i')
		{
			//Checks if row 2 is empty. If not, checks other rows and puts word in first empty row	
			if (*A[2] == 0)
				strcpy(A[2], temp);
			else
			{
				for (a = 3; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 9;
					}
		
				if (a != 10)
					for (b = 0; b < 2; b++)
						if (*A[b] == 0)
						{
							strcpy(A[b], temp);
							b = 10;
						}
			}
		}

		//Checks if word starts with j, k, or l
		else if (*temp == 'j' || *temp == 'k' || *temp == 'l')
		{
			//Checks if row 3 is empty. If not, checks other rows and puts word in first empty row
			if (*A[3] == 0)
				strcpy(A[3], temp);
			else
			{
				for (a = 4; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 9;
					}
		
				if (a != 10)
					for (b = 0; b < 3; b++)
						if (*A[b] == 0)
						{
							strcpy(A[b], temp);
							b = 10;
						}
			}
		}

		//Checks if word starts with m, n, or o
		else if (*temp == 'm' || *temp == 'n' || *temp == 'o')
		{
			//Checks if row 4 is empty. If not, checks other rows and puts word in first empty row
			if (*A[4] == 0)
				strcpy(A[4], temp);
			else
			{
				for (a = 5; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 9;
					}
		
				if (a != 10)
					for (b = 0; b < 4; b++)
						if (*A[b] == 0)
						{
							strcpy(A[b], temp);
							b = 10;
						}
			}
		}

		//Checks if word starts with p, q, or r
		else if (*temp == 'p' || *temp == 'q' || *temp == 'r')
		{
			//Checks if row 5 is empty. If not, checks other rows and puts word in first empty row
			if (*A[5] == 0)
				strcpy(A[5], temp);
			else
			{
				for (a = 6; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 9;
					}
		
				if (a != 10)
					for (b = 0; b < 5; b++)
						if (*A[b] == 0)
						{
							strcpy(A[b], temp);
							b = 10;
						}
			}
		}

		//Checks if word starts with s, t, or u
		else if (*temp == 's' || *temp == 't' || *temp == 'u')
		{
			//Checks if row 6 is empty. If not, checks other rows and puts word in first empty row
			if (*A[6] == 0)
				strcpy(A[6], temp);
			else
			{
				for (a = 7; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 9;
					}
		
				if (a != 10)
					for (b = 0; b < 6; b++)
						if (*A[b] == 0)
						{
							strcpy(A[b], temp);
							b = 10;
						}
			}
		}

		//Checks if word starts with v, w, or x
		else if (*temp == 'v' || *temp == 'w' || *temp == 'x')
		{
			//Checks if row 7 is empty. If not, checks other rows and puts word in first empty row
			if (*A[7] == 0)
				strcpy(A[7], temp);
			else
			{
				for (a = 8; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 9;
					}
		
				if (a != 10)
					for (b = 0; b < 7; b++)
						if (*A[b] == 0)
						{
							strcpy(A[b], temp);
							b = 10;
						}
			}
		}

		//Checks if word starts with y or z
		else if (*temp == 'y' || *temp == 'z')
		{
			//Checks if row 8 is empty. If not, checks other rows and puts word in first empty row
			if (*A[8] == 0)
				strcpy(A[8], temp);
			else
			{
				for (a = 0; a < ROWS; a++)
					if (*A[a] == 0)
					{
						strcpy(A[a], temp);
						a = 10;
					}
			}
		}

		temp = strtok(NULL, " ");
	}
}

//Prints the row number and word stored in array A in that row
//Input: Array of words, A
//Output: Row number and word in that row
void PrintArray(char A[][COLS])
{
	int a;

	for (a = 0; a < ROWS; a++)
			printf("%d %s\n", a, A[a]);
}
