//Jeremy High - 103306452
//Lab 6
//03-60-141-51

//Inclusions
#include <stdio.h>
#include <string.h>

//Declare struct WordStruct
struct WordStruct
{
	char Word[51];
	int length;
} WordList[25], temp;

//Function prototypes
void Tokenize(char []);
void Print(int);
void Sort(int, int);
void SaveList(int);
void Length(int);

int main()
{
	char InputString[] = "the cat in the hat jumped over the lazy fox done";
	
	Tokenize(InputString);

	return 0;
}

//Tokenizes string and puts each word in WordList
//Input: A string
//Output: Each word before "done" into WordList
void Tokenize(char string[])
{
	int i = 0;
	char* hold;

	hold = strtok(string, " ");

	while (strcmp(hold, "done") != 0)
	{
		strcpy(WordList[i].Word, hold);
		hold = strtok(NULL, " ");
		i++;
	}

	printf("Unsorted WordList: ");
	Print(i);
	Length(i);
	Sort(0, i);
	SaveList(i);	
}

//Prints each word in WordList
//Input: Number of words in WordList
//Output: Every word in WordList
void Print(int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf("%s ", WordList[i].Word);

	printf("\n");
}

//Alphabetizes WordList
//Input: 0, number of words in WordList
//Output: WordList alphabetized
void Sort(int start, int end)
{
	int loop = 1;

	while (loop)
	{
		loop = 0;

		for (start = 0; start < end - 1; start++)
			if (strcmp(WordList[start].Word, WordList[start+1].Word) > 0)
			{
				temp = WordList[start];
				WordList[start] = WordList[start+1];
				WordList[start+1] = temp;
				loop = 1;
			}
		
	}

	printf("Sorted WordList: ");
	Print(end);
}

//Finds length of each word and stores in WordList
//Input: Number of words in WordList
//Output: Length of each word in WordList
void Length(int size)
{
	int i;

	for (i = 0; i < size; i++)
		WordList[i].length = strlen(WordList[i].Word);
}

//Saves WordList in file "wlist.txt"
//Input: Number of words in WordList
//Output: WordList in file "wlist.txt"
void SaveList(int size)
{
	int i;
	FILE *file;

	if ((file = fopen("wlist.txt", "w")) == NULL)
		printf("Error\n");
	else
	{
		for (i = 0; i < size; i++)
			fprintf(file, "%s %d\n", WordList[i].Word, WordList[i].length);
	}

	fclose(file);
}
