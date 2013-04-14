#include <stdio.h>

void Product_Array(int[5], int[5]);

void main()
{
	int a;
	int Array1[5], Array2[5];

	printf("Array 1 | Array 2\n");

	for (a = 0; a < 5; a++)
	{
		scanf("%d %d", &Array1[a], &Array2[a]);
	}

	Product_Array(Array1, Array2);
}

void Product_Array(int Array1[5], int Array2[5])
{
	int a, Product_Array[5];

	printf("Product_Array\n");

	for (a = 0; a < 5; a++)
	{
		Product_Array[a] = Array1[a] * Array2[a];
		
		printf("%d\n", Product_Array[a]);
	}
}
