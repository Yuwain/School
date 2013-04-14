//Jeremy High - 103306452
//Assignment 1 - 60-256-51
//September 17th, 2012

//Inclusions
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

//Global Variables
int size = 1;
int found = 0;
char directory[100][20] = {"."};

//Input: The name of the file/directory and the file to search for
//Output: Whether or not the searched file is found and where
//Purpose: To recursively search directories for a certain file
void checkdir(char *dir, char *search)
{
	int n;
	DIR *dp;
	struct dirent *dirp;
	char dirc[100];

	strcpy(directory[size], dir);
	++size;
	strcpy(dirc, ".");
	
	for (n = 1; n < size; n++)
	{
		strcat(dirc, "/");
		strcat(dirc, directory[n]);
	}

	if (opendir(dirc) == NULL)
	{
		if (strcmp(dir, search) == 0)
		{
			fprintf(stdout, "File \"%s\" found at: %s\n", search, dirc);
			found = 1;
		}
	}
	else if ((strcmp(dir, ".") != 0 ) && (strcmp(dir, "..") != 0))
	{
		dp = opendir(dirc);

		while ((dirp=readdir(dp)) != NULL)
			checkdir(dirp -> d_name, search);
	}
	--size;
}


int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if (argc == 1)
	{
		fprintf(stderr, "Error: Was not given anything to search for\n");
		return 0;
	}
	else
		dp = opendir("./");

	while ((dirp=readdir(dp)) != NULL)
		checkdir(dirp -> d_name, argv[1]);

	if (found == 0)
		fprintf(stdout,  "File \"%s\" not found\n", argv[1]);

	closedir(dp);
	return 0;
}
