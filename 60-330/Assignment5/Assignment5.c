/************************************************************
	Written by:			Jeremy High
	Student ID:			103306452
	Written on:			March 25th, 2013

	This program spawns three children and has each
	perform a task after receiving a token via pipe
	from both the parent and the last child process
************************************************************/

/* Inclusions */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

/* Definitions */
#define error	-1	//Used to improve general readability of code

/* Function Prototypes */
void MakePipe(int[2]);
void WriteToPipe(int[2], char[]);
void ReadFromPipe(int[2], char[]);

int main(int argc, char *argv[]) {
	int i,
		status,
		parent,
		child[3],
		exitStatus,
		parentToChild1[2],
		child1ToChild2[2],
		child2ToChild3[2],
		child1ToParent[2],
		parentToChild2[2],
		child2ToParent[2],
		parentToChild3[2],
		child3ToParent[2];
	char command[100],
		 token[] = "GO_AHEAD";

	/* Error handling */
	if (argc != 2) {
		fprintf(stderr, "Usage: ./a.out <file name>\n");
		exit(99);
	}

	/* Create pipes */
	MakePipe(parentToChild1);
	MakePipe(child1ToChild2);
	MakePipe(child2ToChild3);
	MakePipe(child1ToParent);
	MakePipe(parentToChild2);
	MakePipe(child2ToParent);
	MakePipe(parentToChild3);
	MakePipe(child3ToParent);

	/* Set all I/O operations to non-buffered
	   Stderr is unbuffered by default, so we 
	   can have this under the error handling */
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(fdopen(parentToChild1[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(parentToChild1[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(child1ToChild2[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(child1ToChild2[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(child2ToParent[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(child2ToParent[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(child1ToParent[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(child1ToParent[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(parentToChild2[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(parentToChild2[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(child2ToChild3[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(child2ToChild3[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(parentToChild3[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(parentToChild3[1], "w"), NULL, _IONBF, 0);
	setvbuf(fdopen(child3ToParent[0], "r"), NULL, _IONBF, 0);
	setvbuf(fdopen(child3ToParent[1], "w"), NULL, _IONBF, 0);

	/* Produces 3 children */
	for (i = 0; i < 3; ++i) {
		if ((parent = child[i] = fork()) == error) {
			fprintf(stderr, "Could not produce child #%d\n", i+1);
			exit(99);
		}

		if (!parent)
			break;
	}

	/* Send and receive tokens from children and then wait for them to finish */
	if (parent) {
		fprintf(stdout, "I am the parent of the following: %d, %d, and %d\n", child[0], child[1], child[2]);
		
		WriteToPipe(parentToChild1, token);
		ReadFromPipe(child1ToParent, command);
		WriteToPipe(parentToChild2, token);
		ReadFromPipe(child2ToParent, command);
		WriteToPipe(parentToChild3, token);
		ReadFromPipe(child3ToParent, command);

		for (i = 0; i < 3; ++i) {
			waitpid(child[i], &status, 0);
			fprintf(stdout, "From main: child, id #%d ended with status %d\n", child[i], WEXITSTATUS(status));
		}

		fprintf(stdout, "Goodbye!\n");
	} 
	else {
		/* First child */
		if (i == 0) {
			ReadFromPipe(parentToChild1, command);
			
			fprintf(stdout, "I am child #%d and my id is: %d\n", i+1, getpid());
			
			/* Copies file received from argument */
			sprintf(command, "cp %s newcopy.txt", argv[1]);
			exitStatus = system(command);
			
			char done[] = "child1_done";
			
			WriteToPipe(child1ToParent, done);
			WriteToPipe(child1ToChild2, done);

			exit(++exitStatus); 
		} 
		/* Second child */
		else if (i == 1) {
			ReadFromPipe(child1ToChild2, command);
			ReadFromPipe(parentToChild2, command);

			fprintf(stdout, "I am child #%d and my id is: %d\n", i+1, getpid());

			/* Runs ls on /bin and /sbin */
			sprintf(command, "ls /bin /sbin -lR");
			exitStatus = system(command);
			
			char done[] = "child2_done";

			WriteToPipe(child2ToChild3, done);
			WriteToPipe(child2ToParent, done);
			
			exit(++exitStatus); 
		} 
		/* Third child */
		else {
			ReadFromPipe(child2ToChild3, command);
			ReadFromPipe(parentToChild3, command);

			fprintf(stdout, "I am child #%d and my id is: %d\n", i+1, getpid());

			/* Cats file received from argument and source code */
			sprintf(command, "cat %s Assignment5.c", argv[1]);
			exitStatus = system(command);

			char done[] = "child3_done";

			WriteToPipe(child3ToParent, done);

			exit(++exitStatus); 
		}
	}
	
	return 0;
}

/************************************************************
	Reads from pipe into command and then close the pipe

	Pipe	- The pipe that is being read from
	Command	- What is being read from the pipe
************************************************************/
void ReadFromPipe(int pipe[2], char command[]) {
	close(pipe[1]);

	if (read(pipe[0], command, sizeof(command)) == error) {
		fprintf(stderr, "Error reading from pipe\n");
		exit(99);
	}

	close(pipe[0]);

	return;
}

/************************************************************
	Writes token to pipe and then closes the pipe

	Pipe	- The pipe that is being written to
	Token	- What is being written to the pipe
************************************************************/
void WriteToPipe(int pipe[2], char token[]) {
	close(pipe[0]);

	if (write(pipe[1], token, strlen(token)+1) == error) {
		fprintf(stderr, "Error writing to pipe\n");
		exit(99);
	}

	close(pipe[1]);

	return;
}

/************************************************************
 	Creates new pipes and handles errors caused by such

	newPipe	- The pipe that is being created
************************************************************/
void MakePipe(int newPipe[2]) {
	if (pipe(newPipe) == error) {
		fprintf(stderr, "Could not produce pipe\n");
		exit(99);
	}

	return;
}
