//Jeremy High - 103306452
//Lab 4a
//03-60-141-51

#include <stdio.h>

int main()
{
	int a = 7;				//Declare new int variable a and set it to 7
	int *aPtr;				//Declare new int pointer aPtr
	aPtr = &a;				//aPtr equals address of a
	printf("%p\n", &a);		//Prints address of a
	printf("%p\n", aPtr);	//Prints aPtr = address of a
	printf("%p\n", &aPtr);	//Prints address of aPtr
	printf("%d\n", a);		//Prints 7, the value stored in a
	printf("%d\n", *aPtr);	//Prints 7, the value stored in aPtr = address of a
	printf("%p\n", *&aPtr);	//Prints address stored at address of aPtr = address of a
	printf("%p\n", &*aPtr);	//Prints address holding value 7 = address of a
	printf("%d\n", *&a); 	//Prints 7, the value held at address of a
//	printf("%d\n", &*a); 	//Error: * next to int expects multiplication
	return 0;				//Return 0
}
