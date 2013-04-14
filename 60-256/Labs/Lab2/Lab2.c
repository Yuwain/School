#include <stdio.h>

int main(int argc, char *argv[])
{
	char ar[4] = "Bigf";
	int i = 0;

	while(1)
	{
		fputc(ar[i], stdout);
		i = (i+1) % 4;
		sleep(1);
	}
}
