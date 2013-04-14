#include <stdio.h>
#include <math.h>

int ComputeSum (int);
int FindThreeDigit (int, int);
int PrintAll (int, int, int, int, int, int, int);

int main(void)
{

	int num1, num2;
	int sum1, sum2, dig1, dig2;
	int cardnum;

	printf("Type the first four digit number  : ");
	scanf("%d", &num1);
	printf("Type the second four digit number : ");
	scanf("%d", &num2);

	sum1 = ComputeSum(num1);
	sum2 = ComputeSum(num2);

	dig1 = sum1*3;
	dig2 = FindThreeDigit(sum1, sum2);

	cardnum = num1*1000+dig2;

	PrintAll(num1, num2, sum1, sum2, dig1, dig2, cardnum);

	return 0;
}

int ComputeSum(number)
{

	int d1, d2, d3, d4;
	int sum;

	d1 = number/1000;
	d2 = number/100 % 10;
	d3 = number/10 % 10;
	d4 = number % 10;

	sum = d1+d2+d3+d4;

	return (sum);
}

int FindThreeDigit(int num1, int num2)
{

	num1 *= 3;
	num2 += num1;

	return (num2);
}

int PrintAll(int num1, int num2, int sum1, int sum2, int dig1, int dig2, int cardnum)
{

	printf("\n");
	printf("The sum of the first four digits %d is \t: %d\n", num1, sum1);
	printf("The sum of the second four digits %d is \t: %d\n", num2, sum2);
	printf("The three digit number %d * 3 is \t\t: %d\n", sum1, dig1);
	printf("The three digit number %d + %d is \t\t: %d\n", dig1, sum2, dig2);
	printf("The calling card number is \t\t\t: %d\n", cardnum);

	return 0;
}
