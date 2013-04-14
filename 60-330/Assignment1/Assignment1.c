//Jeremy High - 103306452
//Assignment 1 - 03-60-330
//January 26th, 2013

//Inclusions
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
	int i,
		m,
		status,
		parent,
		child[3];
	char command[100];

	if (argc != 2) {
		fprintf(stderr, "Usage: ./a.out <file name>\n");
		return 1;
	}

	for (i = 0; i < 3; i++) {
		if ((parent = child[i] = fork()) == -1) {
			fprintf(stderr, "Could not produce child #%d\n", i+1);
			exit(99);
		}	// End if

		if (!parent)
			break;
	}	// End for

	if (parent) {
		fprintf(stdout, "I am the parent of the following: %d, %d, and %d\n", child[0], child[1], child[2]);

		for (i = 0; i < 3; i++) {
			waitpid(child[i], &status, 0);
			fprintf(stdout, "From main: child, id #%d ended with status %d\n", child[i], WEXITSTATUS(status));
		}	// End for

		fprintf(stdout, "Goodbye!\n");
	} else {
		fprintf(stdout, "I am child #%d and my id is: %d\n", i+1, getpid());

		if (i == 0) {
			sprintf(command, "cp %s newcopy.txt", argv[1]);
			m = system(command);
			exit(++m);
		} else if (i == 1) {
			sprintf(command, "ls /bin /sbin -1R");
			m = system(command);
			exit(++m);
		} else {
			sprintf(command, "cat %s Assignment1.c", argv[1]);
			m = system(command);
			exit(++m);
		}	// End if (i == 0)
	}	// End if (parent)
	
	return 0;
}

