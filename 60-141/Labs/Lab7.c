//Jeremy High - 103306452
//Lab 7 - 60-141-51
//March 13th, 2012

//Inclusions
#include <stdio.h>

//A struct containing two strings and an int
struct employee
{
	char firstname[40];
	char lastname[40];
	int id;
};

//Defines Employee as a type so you don't have call the struct all the time
typedef struct employee Employee;

//Function Prototypes
void InputEmployeeRecord(Employee e[]);
void PrintEmployeeRecord(const Employee e[]);
void SaveEmployeeRecord(const Employee e[], const char *FileName);

void main()
{
	Employee e[3];

	InputEmployeeRecord(e);
	PrintEmployeeRecord(e);
	SaveEmployeeRecord(e, "employee.dat");
}

//Takes names and ID numbers of 3 employees
//Input: An array of type Employee
//Output: Input array filled in with things 
void InputEmployeeRecord(Employee e[])
{
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("First name: ");
		scanf("%s", e[i].firstname);
		printf("Last name: ");
		scanf("%s", e[i].lastname);
		printf("ID #: ");
		scanf("%d", &e[i].id);
	}
}

//Prints out records of employee data
//Input: An unchangeable array of type Employee
//Output: Input array's information printed
void PrintEmployeeRecord(const Employee e[])
{
	int i;

	for (i = 0; i < 3; i++)
		printf("%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname);
}

//Saves contents of employee record to file
//Input: Record 'employee', file name
//Output: File with record in it
void SaveEmployeeRecord(const Employee e[], const char *FileName)
{
	int i;
	FILE *file;

	if ((file = fopen(FileName, "w")) == NULL)
		printf("An error occured");
	else
		for (i = 0; i < 3; i++)
			fprintf(file, "%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname);
}
