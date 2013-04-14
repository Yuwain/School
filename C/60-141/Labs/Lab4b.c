//Jeremy High - 103306452
//Lab 4b
//03-60-141-51

//Inclusions
#include <stdio.h>

//Definitions
#define MAX 20

//Function prototypes
int Triple(int *);
void Swap(int *, int *);
void BubbleSort(int *, int, int);
void PrintArray(int *, int);

int main()
{
	int r;
	int NumList[MAX];
	int *pArray = NumList;

	//Populates array with even numbers increasing from 4
	*pArray = 4;
	for (r = 1; r < MAX; r++)
	{
		pArray++;
		*pArray = *(pArray-1) + 2;
	}

	pArray = &NumList[0];

	PrintArray(pArray, MAX);
	Triple(pArray);
	BubbleSort(pArray, MAX, -1);
	BubbleSort(pArray, MAX, 1);

	return 0;
}

//Function triples values in pointer array
//Input: a pointer array
//Output: pointer array with all values tripled
int Triple(int *D)
{
	int i;

	//Triples each value in array
	for (i = 0; i < MAX; i++)
	{
		*D = *D * 3;
		D++;
	}

	D = D-MAX;
	PrintArray(D, 20);

	return *D;
}

//Function swaps two numbers
//Input: two pointers
//Output: values at two pointers swapped
void Swap(int *A, int *B)
{
	int temp;

	//Swaps two values
	temp = *A;
	*A = *B;
	*B = temp;
}

//Function sorts pointer array according to input order
//Input: pointer array, size of array, sort order
//Output: pointer array sorted by sort order
void BubbleSort(int *array, int size, int order)
{
	int a;
	int loop = 1;

	while (loop)
	{
		loop = 0;

		for (a = 0; a < size-1; a++)
		{
			//Sorts array in ascending order
			if (order == 1)
				if (*array > *(array+1))
					{
						Swap(array, array+1);
						loop = 1;
					}

			//Sorts array in decending order
			if (order == -1)
				if (*array < *(array+1))
					{
						Swap(array, array+1);
						loop = 1;
					}

			array++;
		}

		array = array - (size - 1);
	}

	PrintArray(array, 20);
}

//Function prints pointer array
//Input: pointer array, size of array
//Output: printed array
void PrintArray(int *array, int size)
{
	int a;

	for (a = 0; a < size; a++)
	{
		printf("%d ", *array);
		array++;
	}

	printf("\n");
}
