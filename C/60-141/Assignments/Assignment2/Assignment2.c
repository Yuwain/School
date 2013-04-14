//Jeremy High - 103306452
//Assignment 2
//60-141-51
//March 6th, 2012

//Inclusions
#include <stdio.h>
#include <string.h>

//Function Prototypes
void Solve(char *, int);
float ScaleNum(float, char);

void main()
{
	int num, a;
	char string[100];

	scanf("%d", &num);

	for (a = 0; a <= num; a++)
	{
		fgets(string, 100, stdin);

		Solve(string, a);
	}
}

//Takes in word problem (with P=x, I=x or U=x) and spits out answer
//Input: Word problem
//Output: Answer to problem
void Solve(char *string, int a)
{
	float U, I, P;
	char *loc, *loc2, scale;

	//Checks if P is first number, gets P
	if ((loc = strstr(string, "P=")) != NULL)
	{
		sscanf(loc, "%*c%*c%f%c", &P, &scale);
		P = ScaleNum(P, scale);

		//Checks if U is second number, gets U and solves for I
		if ((loc2 = strstr(loc, "U=")) != NULL)
		{
			sscanf(loc2, "%*c%*c%f%c", &U, &scale);
			U = ScaleNum(U, scale);

			printf("Problem #%d:\nI=%0.2fA\n", a, (P/U));
		}

		//Checks if I is second number, gets I and solve for U
		else if ((loc2 = strstr(loc, "I=")) != NULL)
		{
			sscanf(loc2, "%*c%*c%f%c", &I, &scale);
			I = ScaleNum(I, scale);

			printf("Problem #%d:\nU=%0.2fV\n", a, (P/I));
		}
	}

	//Checks if U is first number, gets U
	if ((loc = strstr(string, "U=")) != NULL)
	{
		sscanf(loc, "%*c%*c%f%c", &U, &scale);
		U = ScaleNum(U, scale);

		//Checks if I is second number, gets I and solves for P
		if ((loc2 = strstr(loc, "I=")) != NULL)
		{
			sscanf(loc2, "%*c%*c%f%c", &I, &scale);
			I = ScaleNum(I, scale);

			printf("Problem #%d:\nP=%0.2fW\n", a, (U*I));
		}

		//Checks if P is second number, gets P and solves for I
		else if ((loc2 = strstr(loc, "P=")) != NULL)
		{
			sscanf(loc2, "%*c%*c%f%c", &P, &scale);
			P = ScaleNum(P, scale);
		
			printf("Problem #%d:\nI=%0.2fA\n", a, (P/U));
		}
	}

	//Checks if I is first number, gets I
	if ((loc = strstr(string, "I=")) != NULL)
	{
		sscanf(loc, "%*c%*c%f%c", &I, &scale);
		I = ScaleNum(I, scale);

		//Checks if P is second number, gets P and solves for U
		if ((loc2 = strstr(loc, "P=")) != NULL)
		{
			sscanf(loc2, "%*c%*c%f%c", &P, &scale);
			P = ScaleNum(P, scale);

			printf("Problem #%d:\nU=%0.2fV\n", a, (P/I));
		}

		//Checks if U is second number, gets U and solves for P
		else if ((loc2 = strstr(loc, "U=")) != NULL)
		{
			sscanf(loc2, "%*c%*c%f%c", &U, &scale);
			U = ScaleNum(U, scale);

			printf("Problem #%d:\nP=%0.2fW\n", a, (U*I));
		}
	}
}

//Takes number and prefix (m, M, k) and returns number in regards to base
//Input: number and prefix
//Output: number in regards to base scale
float ScaleNum(float num, char scale)
{
	if (scale == 'm')
		num = num/1000;
	else if (scale == 'k')
		num = num * 1000;
	else if (scale == 'M')
		num = num * 1000000;

	return num;
}
