#include <stdio.h>
#include <stdlib.h>

void main()
{
	int loop = 1;
	
	while (loop)
	{
		printf("Help, I'm stuck in a loop");
		malloc(100);
	}
}
