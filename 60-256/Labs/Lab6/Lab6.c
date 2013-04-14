#include <stdio.h>

int main(int argc, char *args[]) 
{
	int PID;
	char op;
	FILE *f;
	float a, b;

	PID = fork();
	
	if (PID > 0) 
	{
		fprintf(stdout, "Parent\n");
		
		while(f=fopen("temp.txt", "r"))
		{
			fclose(f);
			sleep(1);
		}

		scanf("%f %f %c", &a, &b, &op);
		fprintf(f, "%f %f %c\n", a, b, op);
		fclose(f);
		sleep(3);
	}
	else
	{
		while (!(f=fopen("temp.txt", "r")))
			sleep(1);

		fprintf(stdout, "Child\n");

		fscanf(f, "%f %f %c", &a, &b, &op);
		fclose(f);
		unlink("temp.txt");
		sleep(1);
	}
}
