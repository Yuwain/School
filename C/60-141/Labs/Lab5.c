//Jeremy High, 103306452
//Lab 5
//03-60-141-51

#include <stdio.h>
#include <string.h>

//Function Prototypes
void Reverse(char[]);
void RecursiveReverse(char[], int, int);
void ParseSentence(char[]);

int main()
{
	//Declares a char array Buffer1 and initializes to "This is the first buffer"
	char Buffer1[] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h',
			 		  'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 
			  	  	  'f', 'f', 'e', 'r', '\0'};
	
	//Declares a char array Buffer2 and initializes to "This is the second buffer"
	char Buffer2[] = "This is the second buffer";

	//Declares a char array Buffer3
	char Buffer3[80]; 
	char Parse[] = "hello world, how are you today.";
	char* pBuffer;
	int a, b = 0;

	pBuffer = Buffer3;

	scanf("%[^\n]s", Buffer3);
	printf("\nBuffer 1: %s\nBuffer 2: %s\nBuffer 3: ", Buffer1, Buffer2);

	//Prints contents of Buffer3 via while loop 
	while (*pBuffer != '\0')
	{
		printf("%c", *pBuffer);
		pBuffer++;
	}
	printf("\n");

	pBuffer = Buffer3;
	a = (int)strlen(pBuffer) - 1;

	Reverse(pBuffer);
	RecursiveReverse(pBuffer, a, b);
	ParseSentence(Parse);

	return 0;
}

//Reverses a char array
//Input: A char array
//Output: Char array in reverse
void Reverse(char string[])
{
	int size, b;
	int a = 0;
	char temp;

	size = (int)strlen(string);
	b = size - 1;

	while (a != size/2)
	{
		temp = string[a];
		string[a] = string[b];
		string[b] = temp;
		a++;
		b--;
	}

	printf("Reversed buffer 3: %s\n", string);
}

//Reverses a char array recursively
//Input: A char array, last character's position, first character's position
//Output: Char array in reverse
void RecursiveReverse(char string[], int a, int b)
{
	char temp;

	if (b != strlen(string)/2)
	{
		temp = string[a];
		string[a] = string[b];
		string[b] = temp;

		RecursiveReverse(string, a-1, b+1);
	}
	else
		printf("Recursively reversed: %s\n", string);
}

//Splits a sentence into each word and sorts alphabetically
//Input: A sentence
//Output: All words in the sentence sorted alphabetically
void ParseSentence(char sentence[])
{
	int a, loop, i = 0;
	char* sent[10];
	char* temp;

	//Tokenizes sentence and puts tokens into array
	sent[i] = strtok(sentence, " ,;.?");

	while (sent[i] != NULL)
	{
		i++;
		sent[i] = strtok(NULL, " ,;.?");
	}

	i--;

	//Bubble sort the list of words
	while (loop)
	{
		loop = 0;

		for (a = 0; a < i; a++)
			if (strcmp(sent[a], sent[a+1]) > 0)
			{
				temp = sent[a];
				sent[a] = sent[a+1];
				sent[a+1] = temp;
				loop = 1;
			}
	}

	//Print the sorted list of words
	for (a = 0; a <= i; a++)
		printf("%s\n", sent[a]);
}
