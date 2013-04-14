//Jeremy High 	- 103306452
//Assignment 5 	- 03-60-256-01
//November 16th, 2012

//Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//Definitions
#define false 	0
#define true	1
typedef int bool;

//Color Definitions
#define BLUE	"\x1b[34m"
#define RESET	"\x1b[0m"

//Function Prototypes
int readArgs(const char *, char *[]);

int main(int argc, char *argv[])
{
	int	status;
	bool ampersand; 
	char *temp,
		 line[255],
		 *argList[20];
	pid_t pid;

	fprintf(stdout, "This program executes commands/programs for you\n");

	while (true)
	{
		fprintf(stdout, "Enter " BLUE "Ctrl-C " RESET "to exit, or enter a program name with its arguments: ");
		fgets(line, 255, stdin);

		temp = strtok(line, ";");

		while (temp != NULL)
		{
			ampersand = readArgs(temp, argList);

			if ((pid = fork()) == -1)
			{
				perror("Impossible to fork");
				exit(1);
			}

			if (pid > 0)
			{
				if (ampersand)
					fprintf(stdout, "Process [%d]\n", pid);
				else
				{
					waitpid(pid, &status, 0);
					fprintf(stdout, "My child has terminated\n\n");
				}
			}
			else
				if (execvp(argList[0], argList) == -1)
				{
					perror("Child process");
					exit(22);
				}

			temp = strtok(NULL, ";");
		}
	}

	exit(0);
}

bool readArgs(const char *line, char *argList[])
{
	int i = 0,
	    offset = 0;
	char name[50];
	bool found = false;
	static bool yes = false;

	while (yes & (argList[i] != NULL))
		free(argList[i++]);

	i = 0;

	while (sscanf(line+offset, "%s", name) == 1) 
	{
		argList[i] = (char *)malloc(strlen(name)+1);
		strcpy(argList[i++], name);

		while (line[offset] == ' ')
			offset++;

		offset += strlen(name);
	}

	if (!strcmp(argList[i-1], "&"))
	{
		argList[i-1] = NULL;
		found = true;
	}
	else
	{
		if (argList[i-1][strlen(argList[i-1])-1] == '&')
		{
			argList[i-1][strlen(argList[i-1])-1] = '\0';
			found = true;
		}
		
		argList[i] = NULL;
	}

	yes = true;

	return found;
}
