//Jeremy High - 103306452
//Lab 8 - 60-141-51
//March 20th, 2012

//Inclusions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Struct we will be using to store our list
struct point
{
	int x;
	int y;
	char label[21];
	struct point *ptrNext;
};

typedef struct point Point;

//Function Prototypes
int isEmptyList(Point *ptrF);
void PrintList(Point *ptrF);
void ResetList(Point **ptrF, Point **ptrL);
void AddToBeginning(Point **ptrF, Point **ptrL);
void AddToEnd(Point **ptrF, Point **ptrL);
void SaveList(Point *ptrF);
void LoadList(Point **ptrF, Point **ptrL);

void main()
{
	char temp[5];
	int choice, loop = 1;
	Point *ptrFirst = NULL;
	Point *ptrLast = NULL;

	while (loop)
	{
		printf("1. Add to beginning of list\n"
			   "2. Add to end of list\n"
			   "3. Check if list is empty\n"
			   "4. Reset the list\n"
			   "5. Display the list\n"
			   "6. Save the list to file\n"
			   "7. Load the list from file\n"
			   "0. Exit\n"
			   "> ");
		fgets(temp, 5, stdin);
		sscanf(temp, "%d", &choice);

		switch (choice)
		{
			case 1:  AddToBeginning(&ptrFirst, &ptrLast);
					 break;
			case 2:  AddToEnd(&ptrFirst, &ptrLast);
					 break;
			case 3:  if (isEmptyList(ptrFirst))
						 printf("List isn't empty\n");
					 else
						 printf("List is empty\n");
					 break;
			case 4:  ResetList(&ptrFirst, &ptrLast);
					 break;
			case 5:  PrintList(ptrFirst);
					 break;
			case 6:  SaveList(ptrFirst);
					 break;
			case 7:  LoadList(&ptrFirst, &ptrLast);
					 break;
			case 0:  ResetList(&ptrFirst, &ptrLast);
					 printf("Goodbye\n");
					 loop = 0;
					 break;
			default: printf("Invalid option");
		}
	}
}

//Input: Pointers ptrF and ptrL
//Output: List with point added to beginning
//Purpose: To add a new element to the start of the list
void AddToBeginning(Point **ptrF, Point **ptrL)
{
	Point *new;
	int x, y, i = 0;
	char temp[5], label[21];
	new = malloc(sizeof(Point));

	printf("Enter a point for x: ");
	fgets(temp, 5, stdin);
	sscanf(temp, "%d", &x);
	printf("Enter a point for y: ");
	fgets(temp, 5, stdin);
	sscanf(temp, "%d", &y);
	printf("Enter a label for this point: ");
	fgets(label, 21, stdin);

	while (label[i++] != '\0')
		if (label[i] == '\n')
			label[i] = '\0';

	new->x = x;
	new->y = y;
	strcpy(new->label, label);
	new->ptrNext = NULL;

	if (*ptrF == NULL && *ptrL == NULL)
	{
		*ptrF = new;
		*ptrL = new;
	}
	else
	{
		new->ptrNext = *ptrF;
		*ptrF = new;
	}
}

//Input: Pointers ptrF and ptrL
//Ouput: List with point added to end of list
//Purpose: To add to the end of the list
void AddToEnd(Point **ptrF, Point **ptrL)
{
    Point *new;
    int x, y, i = 0;
    char temp[5], label[21];
    new = malloc(sizeof(Point));

    printf("Enter a point for x.\n");
    fgets(temp, 5, stdin);
    sscanf(temp, "%d", &x);
    printf("Enter a point for y.\n");
    fgets(temp, 5, stdin);
    sscanf(temp, "%d", &y);
    printf("Enter a label for this point\n");
    fgets(label, 21, stdin);

    while (label[i++] != '\0')
        if(label[i] == '\n') 
			label[i] = '\0';
    
	new->x = x;
    new->y = y;
    strcpy(new->label,label);
    new->ptrNext = NULL;

    if(*ptrF == NULL && *ptrL == NULL) 
	{
        *ptrF = new;
        *ptrL = new;
    } 
	else 
	{
        (*ptrL)->ptrNext = new;
        *ptrL = new;
    }
}

//Input: Pointer ptrF
//Output: Displays list on screen
//Purpose: To display list on screen
void PrintList(Point *ptrF)
{
    int i = 0, j = 1;
    Point *current;
    current = ptrF;

    if(current == NULL) 
	{
		printf("Nothing to print!\n");
	}
	else 
	{
		while (current != NULL) 
		{
            printf("Item No.%d\n", j);
            
			while (current->label[i++] != '\0')
                if(current->label[i] == '\n') 
					current->label[i] = '\0';
         
			i = 0;
            
			printf("%s: (%d, %d)\n", current->label, current->x, current->y);
            current = current->ptrNext;
            j++;
        }
	}
}

//Input: Pointers ptrF and ptrL
//Output: Resets ptrF and ptrL to NULL
//Purpose: To free memory and reset ptrF and ptrL
void ResetList(Point **ptrF, Point **ptrL)
{
    Point *tmp;
    while(*ptrF != NULL)
    {
        tmp = (*ptrF)->ptrNext;
        free(*ptrF);
        *ptrF = tmp;
    }
	*ptrL = tmp;
}

//Input: Pointer ptrF
//Output: File list.txt with list saved to it
//Purpose: To save list to a file
void SaveList(Point *ptrF)
{
    Point *current;
    current = ptrF;
    FILE *filePtr;

    if((filePtr = fopen("list.txt", "w")) == NULL)
        printf("Error opening file!\n");
    else 
	{
        while(current != NULL) 
		{
            fprintf(filePtr, "%s\n%d\n%d\n", current->label, current->x, current->y);
            current = current->ptrNext;
    	}
        printf("List saved successfully\n");
    }
    
	fclose(filePtr);
}

//Input: pointers ptrF and ptrL
//Output: List with values taken from file 
//Purpose: To load a list from a file
void LoadList(Point **ptrF, Point **ptrL)
{
    Point *current;
    unsigned int x, y, i = 0;
    char line[21];
    FILE *filePtr;

    if((filePtr = fopen("list.txt", "r")) == NULL)
        printf("Error opening file!\n");
    else 
	{
        while(fgets(line, 21, filePtr) != NULL) 
		{
            current = malloc(sizeof(Point));
        	strcpy(current->label,line);
//			printf("%s\n", current->label);
            fgets(line, 21, filePtr);
            sscanf(line, "%d", &x);
            current->x = x;
            fgets(line, 21, filePtr);
            sscanf(line, "%d", &y);
            current->y = y;
            current->ptrNext = NULL;

            if(*ptrF == NULL && *ptrL == NULL) 
			{
                *ptrF = current;
                *ptrL = current;
        	} 
			else 
			{
                (*ptrL)->ptrNext = current;
                *ptrL = current;
            }
        }
        printf("File loaded successfully.\n");
    }
    
	fclose(filePtr);
}

//Input: Pointer ptrF
//Output: Returns 0 if list is empty and 1 otherwise
//Purpose: Check if list is empty
int isEmptyList(Point *ptrF)
{
    return ptrF == NULL ? 0 : 1;
}
