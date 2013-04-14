//Jeremy High 	- 103306452
//Assignment 4 	- 60-256-01
//November 6th, 2012

//Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definitions
#define false	0
#define true	1
typedef int bool;

//Color Definitions
#define RED		"\x1b[31m"
#define BLUE	"\x1b[34m"
#define RESET	"\x1b[0m"

//Input: A character, number
//Output: Whether or not the input character is a number
//Purpose: To check if the input is a letter
bool checkNum(char alph)
{
	if ((int)alph >= 48 && (int)alph <= 57)
		return true;
	else
		return false;
}

int main(int argc, char *args[])
{
	int size,
	    index = 0,
	bool aChar = true,
	     aNum  = false;
	char alphnum,
	     buffer[BUFSIZ],
	     numSum[BUFSIZ],
	     numDif[BUFSIZ];
	double sum,
	       diff,
	       numOne,
	       numTwo;

	while (aChar)
	{
		memset(buffer, '\0', sizeof(buffer));
		fflush(stdin);
		
		aChar = false;
		index = 0;

		fprintf(stdout, "Please enter the " RED "first " RESET "number:\t");

		while ((fread(&alphnum, 1, 1, stdin)))
		{
			if (alphnum =='\n')
				break;
	
			aNum = checkNum(alphnum);
	
			if (!aNum)
				aChar = true;
			else
				buffer[index++] = alphnum;
		}
	}
	
	buffer[++index] = '\0';
	numOne = atof(buffer);

	aChar = true;
	aNum = false;
	
	while (aChar)
	{
		memset(buffer, '\0', sizeof(buffer));
		fflush(stdin);	

		aChar = false;
		index = 0;

		fprintf(stdout, "Please enter the " BLUE "second " RESET "number:\t");
		
		while ((fread(&alphnum, 1, 1, stdin)))
		{
			if (alphnum == '\n')
				break;
	
			aNum = checkNum(alphnum);
		
			if (!aNum)
				aChar = true;	
			else
				buffer[index++] = alphnum;
		}
	}

	buffer[++index] = '\0';
	numTwo = atof(buffer);
	
	sum = numOne + numTwo;
	diff = numOne - numTwo;	

	sprintf(numSum, "%.2lf", sum);
	sprintf(numDif, "%.2lf", diff);

	size = strlen(numSum);

	fprintf(stdout, "Addition:\t " RED " %.2lf\n" RESET 
			"\t\t+ " BLUE "%.2lf\n" RESET 
			"\t\t= ", numOne, numTwo);
	fwrite(numSum, size, 1, stdout);

	size = strlen(numDif);

	fprintf(stdout, "\nSubtraction:\t " RED " %.2lf\n" RESET 
			"\t\t- " BLUE "%.2lf\n" RESET 
			"\t\t= ", numOne, numTwo);
	fwrite(numDif, size, 1, stdout);
	fprintf(stdout, "\n");

	return 0;
}
