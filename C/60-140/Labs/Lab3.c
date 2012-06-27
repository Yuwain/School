#include <stdio.h>

void FindSum(int, int, int *);

int main(void)
{
	int a=2, b=5, c=1, x=3, y=4, z=7;

	FindSum(a, b, &c);
	printf("First call in main %d %d %d %d %d %d \n", a, b, c , x, y, z);
	FindSum(x, y, &z);
	printf("Second call in main %d %d %d %d %d %d \n", a, b, c, x, y, z);

	return 0;
}


void FindSum (int a, int b, int *c)
{
	a += (b*2);
	b += (b*2);
	*c += (b*2);
	printf("in FindSum: %d %d %d \n", a, b, *c);
}
