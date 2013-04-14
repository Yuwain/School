//Jeremy High 	- 103306452
//Assignment 1 	- 60-254-51
//September 13th, 2012

//Inclusions
#include <stdio.h>

//Struct containing our stack
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
void push(int x)
{
	if (s1.size == 10)
		printf("Stack overflow\n");
	else
	{
		s1.items[s1.size] = x;
		s1.size++;
	}
}

//Input: None
//Output: Returns top and removes it
//Purpose: To return and remove top item from stack
void pop()
{
	if (s1.size == 0)
		printf("The stack is empty\n");
	else
		printf("The top was: %d\n", s1.items[s1.size-1]);
	s1.size--;
	s1.items[s1.size] = 0;
}

//Input: None
//Output: Returns the top of the stack
//Purpose: To show us what's on top of the stack
void top()
{
	if (s1.size == 0)
		printf("The stack is empty\n");
	else
		printf("The top is: %d\n", s1.items[s1.size-1]);
}

//Input: None
//Output: The size of the stack
//Purpose: To return the size of the stack
void size()
{
	printf("The size of the stack is: %d\n", s1.size);
}

//Input: None
//Output: True if stack is empty, false otherwise
//Purpose: To tell us if the stack is empty or not
void isEmpty()
{
	if (s1.size == 0)
		printf("True\n");
	else
		printf("False\n");
}

int main()
{
	int loop = 1;
	int choice, x;

	while (loop)
	{
		printf("1 - Push\n"
			   "2 - Pop\n"
			   "3 - Top\n"
			   "4 - Size\n"
			   "5 - isEmpty\n"
			   "6 - Exit\n"
			   "> ");
		scanf("%d", &choice);
		
		
		switch (choice)
		{
			case 1:  if (s1.size == 10)
						 printf("Stack overflow\n");
					 else
					 {
				 	 	printf("Add a number to the top of the stack\n");
					 	scanf("%d", &x);
					 	push(x);
					 }
			 		 break;
			case 2:  pop();
					 break;
			case 3:  top();
					 break;
			case 4:  size();
					 break;
			case 5:  isEmpty();
					 break;
			case 6:  loop = 0;
					 printf("Exiting\n");
					 break;
			default: printf("Not an option\n");
		}
	}

	return 0;
}
