#include <stdio.h>

void Sum(int [], int []);

void main()
{
	int r, array1[5], array2[5];

	printf("Array 1 | Array 2\n");
	
	for (r = 0; r < 5; r++)
	{
		scanf("%d %d", &array1[r], &array2[r]);
	}

	Sum(array1, array2);
}

void Sum(int array1[], int array2[])
{
	int r, array3[5];

	printf("Sum_Array\n");

	for (r = 0; r < 5; r++)
	{
		array3[r] = array1[r] + array2[r];
		printf("%d\n", array3[r]);
	}
}
