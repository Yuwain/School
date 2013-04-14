/**********************************************************
	Written by:			Jeremy High
	Student ID:			103306452
	Written on:			February 23rd, 2013

	This program spawns three children and has each
	perform a task after receiving a token via pipe
**********************************************************/

/* Inclusions */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

/* Definitions */
#define error	-1	//Used to improve general readability of code

int main(int argc, char *argv[]) {
	int i,
		status,
		parent,
		child[3],
		exitStatus,
		pipeOne[2],
		pipeTwo[2],
		pipeThree[2];
	char command[100],
		 token[] = "GO_AHEAD";

	/* Error handling */
	if (argc != 2) {
		fprintf(stderr, "Usage: ./a.out <file name>\n");
		exit(99);
	}
	
	if (pipe(pipeOne) == error) {
		fprintf(stderr, "Could not produce first pipe\n");
		exit(99);
	}

	if (pipe(pipeTwo) == error) {
		fprintf(stderr, "Could not produce second pipe\n");
		exit(99);
	}

	if (pipe(pipeThree) == error) {
		fprintf(stderr, "Could not produce third pipe\n");
		exit(99);
	}

	/* Set all I/O operations to non-buffered
	 * Stderr is unbuffered by default, so we 
	 * can have this under the error handling */
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(fdopen(pipeOne[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(pipeOne[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(pipeTwo[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(pipeTwo[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(pipeThree[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(pipeThree[1], "w"), NULL, _IONBF, 0);

	/* Produces 3 children */
	for (i = 0; i < 3; i++) {
		if ((parent = child[i] = fork()) == error) {
			fprintf(stderr, "Could not produce child #%d\n", i+1);
			exit(99);
		}

		if (!parent)
			break;
	}

	/* Write token to pipeOne and wait for children to exit */
	if (parent) {
		fprintf(stdout, "I am the parent of the following: %d, %d, and %d\n", child[0], child[1], child[2]);
		
		close(pipeOne[0]);

		if (write(pipeOne[1], token, strlen(token)+1) == error) {
			fprintf(stderr, "Error writing to pipeOne\n");
			exit(99);
		}

		for (i = 0; i < 3; i++) {
			waitpid(child[i], &status, 0);
			fprintf(stdout, "From main: child, id #%d ended with status %d\n", child[i], WEXITSTATUS(status));
		}

		close(pipeOne[1]);

		fprintf(stdout, "Goodbye!\n");
	} 
	else {
		/* First child */
		if (i == 0) {
			close(pipeOne[1]);

			/* Gets token from parent */
			if (read(pipeOne[0], command, sizeof(command)) == error) {
				fprintf(stderr, "Error reading from pipeOne\n");
				exit(99);
			}
			
			close(pipeOne[0]);
			
			fprintf(stdout, "I am child #%d and my id is: %d\n", i+1, getpid());
			
			/* Copies file received from argument */
			sprintf(command, "cp %s newcopy.txt", argv[1]);
			exitStatus = system(command);
			
			close(pipeTwo[0]);
			
			/* Sends token to child 2 */
			if (write(pipeTwo[1], token, strlen(token)+1) == error) {
				fprintf(stderr, "Error writing to pipeTwo\n");
				exit(99);
			}

			close(pipeTwo[1]);

			exit(++exitStatus); 
		} 
		/* Second child */
		else if (i == 1) {
			close(pipeTwo[1]);
			
			/* Gets token from child 1 */
			if (read(pipeTwo[0], command, sizeof(command)) == error) {
				fprintf(stderr, "Error reading from pipeTwo\n");
				exit(99);
			}

			close(pipeTwo[0]);

			fprintf(stdout, "I am child #%d and my id is: %d\n", i+1, getpid());

			/* Runs ls on /bin and /sbin */
			sprintf(command, "ls /bin /sbin -lR");
			exitStatus = system(command);
			
			close(pipeThree[0]);
			
			/* Sends token to child 3 */
			if (write(pipeThree[1], token, strlen(token)+1) == error) {
				fprintf(stderr, "Error writing to pipeThree\n");
				exit(99);
			}

			close(pipeThree[1]);
			
			exit(++exitStatus); 
		} 
		/* Third child */
		else {
			close(pipeThree[1]);

			/* Gets token from child 2 */
			if (read(pipeThree[0], command, sizeof(command)) == error) {
				fprintf(stderr, "Error reading from pipeTwo\n");
				exit(99);
			}

			fprintf(stdout, "I am child #%d and my id is: %d\n", i+1, getpid());

			/* Cats file received from argument and source code */
			sprintf(command, "cat %s Assignment3.c", argv[1]);
			exitStatus = system(command);
			exit(++exitStatus); 
		}	// End if (i == 0):96
	}	// End if (parent):78
	
	return 0;
}
