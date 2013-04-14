//Jeremy High - 103306452
//Lab 7 - 60-141-51
//March 13th, 2012

//Inclusions
#include <stdio.h>

//Struct containing two strings and an int
struct employee
{
	char firstname[40];
	char lastname[40];
	int id;
};

//Defines EmployeeList as a type so we don't have to call struct all the time
typedef struct employee EmployeeList;

//Function Prototypes
void ReadFile(EmployeeList e[]);
void WriteFile(EmployeeList e[]);
void WordCap(char *);

void main()
{
	EmployeeList e[3];

	ReadFile(e);
	WriteFile(e);
}

//Reads data from a file
//Input: EmployeeList array e
//Output: Array e filled with info
void ReadFile(EmployeeList e[])
{
	int i;
	FILE *file;

	if ((file = fopen("employee.dat", "r")) == NULL)
		printf("Error opening file employee.dat");
	else
		for (i = 0; i < 3; i++)
			fscanf(file, "%d %s %s", &e[i].id, e[i].firstname, e[i].lastname);
}

//Writes data to a file
//Input: EmployeeList array e
//Output: A file with array e stored in it
void WriteFile(EmployeeList e[])
{
	int i;
	FILE *file;

	if ((file = fopen("employee.dat", "w")) == NULL)
		printf("Error opening file employee.dat");
	else
	{
		fprintf(file, "ID FIRSTNAME LASTNAME\n");

		for (i = 0; i < 3; i++)
		{
			WordCap(e[i].firstname);
			WordCap(e[i].lastname);
			fprintf(file, "%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname);
		}
	}
}

//Capitalizes first letter of input word
//Input: A string
//Output: String with first letter capitalized
void WordCap(char cap[])
{
	cap[0] = toupper(cap[0]);
}
