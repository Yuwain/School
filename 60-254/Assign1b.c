//Jeremy High 	- 103306452
//Assignment 1 	- 60-254-51
//September 13th, 2012

//Inclusions
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Global Variables
int loop = 1;

//The stack that our numbers are stored in
struct STACK
{
	int size;
	int items[10];
};

typedef struct STACK stack;

stack s1;

//Input: An integer x
//Output: Stack with the input x on the top
//Purpose: To push something to the top of the stack
void Push(int x)
{
	if (s1.size == 10)
		fprintf(stderr, "Stack overflow\n");
	else
	{
		s1.items[s1.size] = x;
		s1.size++;
	}
}

//Input: None
//Output: Returns top and removes it
//Purpose: To return and remove top item from stack
void Pop()
{
	s1.size--;
	s1.items[s1.size] = 0;
}

//Input: None
//Output: The first item in the stack (the answer)
//Purpose: To print out the answer
void Answer()
{
	if (s1.size > 1)
		fprintf(stderr, "Too many numbers left over, apply %d more operation(s)\n", s1.size-1);
	else
	{
		printf("The answer is: %d\n", s1.items[s1.size-1]);
		loop = 0;
	}
}

//Input: A character, op
//Output: Stack with operation applied to top two numbers
//Purpose: To apply our operation to the top two elements of the stack
void Math(char op)
{
	if (s1.size <= 1 && (op == '*' || op == '+' || op == '-'))
		fprintf(stderr, "Invalid entry: not enough numbers entered\n");
	else
	{
		if (op == '*')
		{
			s1.items[s1.size-2] = s1.items[s1.size-1] * s1.items[s1.size-2];
			Pop();
		}
		else if (op == '+')
		{
			s1.items[s1.size-2] = s1.items[s1.size-1] + s1.items[s1.size-2];
			Pop();
		}
		else if (op == '-')
		{
			s1.items[s1.size-2] = s1.items[s1.size-2] - s1.items[s1.size-1];
			Pop();
		}
		else
			fprintf(stderr, "Invalid entry: invalid operator\n");
	}
}

int main(int argc, char *argv[])
{
	int num;
	char input[10], *temp, hold;
	
	printf("Post-fix calculator. Please enter a number or an operation (+, -, *) "
		   "one per line. Enter '=' to display answer\n");

	while (loop)
	{
		fgets(input, 10, stdin);

		temp = strtok(input, " \n");
		strcpy(input, temp);

		if (strlen(input) > 1)
		{
			num = atoi(input);
			Push(num);
		}
		else
		{
			hold = input[0];

			if (isdigit(hold))
			{
				num = atoi(input);
				Push(num);
			}
			else
			{
				if (hold == '=')
					Answer();
				else
					Math(hold);
			}
		}
	}

	return 0;
}
