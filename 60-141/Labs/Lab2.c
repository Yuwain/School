// Jeremy High
// 03-60-141-51
// 103306452

#include <stdio.h>

int sum1(int);
int sum2(int);
int Fibonacci(int);
int GCD(int, int);
int Power(int, int);
int Print(int);
int DrawTriangle(int);
int DrawTriangle2(int);
int sum1non(int);
int sum2non(int);
int Fibonaccinon(int);
int GCDnon(int, int);
int Powernon(int, int);
int Printnon(int);
int DrawTrianglenon(int);
int DrawTriangle2non(int);

int main(void)
{
	int num, n, t, ans, loop = 1;

	while (loop)
	{
		printf("Select program:\n"
		       " 0 - Exit\n"
		       "Recursive\n"
		       " 1 - Summation of naturals\n"
		       " 2 - Summation of (i+1)^2\n"
		       " 3 - Fibonacci\n"
		       " 4 - GCD\n"
		       " 5 - Power\n"
		       " 6 - Print\n"
     		       " 7 - DrawTriangle\n"
		       " 8 - DrawTriangle2\n"
		       "Non-Recursive\n"
		       " 9 - Summantion of naturals\n"
		       "10 - Summation of (i+1)^2\n"
		       "11 - Fibonacci\n"
		       "12 - GCD\n"
		       "13 - Power\n"
		       "14 - Print\n"
		       "15 - DrawTriangle\n"
		       "16 - DrawTriangle2\n");
		scanf("%d", &num);

		switch (num)
		{
			case 0:  loop = 0;
				 break;
			case 1:  printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 ans = sum1(n);
				 printf("%d\n", ans);
				 break;
			case 2:  printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 ans = sum2(n);
				 printf("%d\n", ans);
				 break;
			case 3:  printf("Please enter a non-negative integer: ");
				 scanf("%d", &n);
				 ans = Fibonacci(n);
				 printf("%d\n", ans);
				 break;
			case 4:  printf("Please enter two integers: ");
				 scanf("%d %d", &n, &t);
				 ans = GCD(n,t);
				 printf("%d\n", ans);
				 break;
			case 5:  printf("Please enter two integers: ");
				 scanf("%d %d", &n, &t);
				 ans = Power(n,t);
				 printf("%d\n", ans);
				 break;
			case 6:  printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 Print(n);
				 break;
			case 7:  printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 DrawTriangle(n);
				 break;
			case 8:  printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 DrawTriangle2(n);
				 break;
			case 9:  printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 sum1non(n);
				 break;
			case 10: printf("Please enter a natural number: ");
		 		 scanf("%d", &n);
				 sum2non(n);
				 break;
			case 11: printf("Please enter a non-negative integer: ");
				 scanf("%d", &n);
				 Fibonaccinon(n);
				 break;
			case 12: printf("Please enter two integers: ");
				 scanf("%d %d", &n, &t);
				 GCDnon(n,t);
				 break;
			case 13: printf("Please enter two integers: ");
				 scanf("%d %d", &n, &t);
				 Powernon(n,t);
				 break;
			case 14: printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 Printnon(n);
				 break;
			case 15: printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 DrawTrianglenon(n);
				 break;
			case 16: printf("Please enter a natural number: ");
				 scanf("%d", &n);
				 DrawTriangle2non(n);
				 break;
			default: printf("Invalid option\n");
		}
	}
	
	printf("Ending program. Goodbye\n");

	return 0;
}

int sum1(int n)
/*Function used to calculate sum of natural numbers from 1 to n
  Assumes a natural number is input
  Prints numbers from n to 1 and their sum*/
{					
	if (n == 1)			
	{				
		printf("%d = ", n);

		return n;
	}
	else
	{
		printf("%d + ", n);

		return sum1(n-1) + n;
	}
}

int sum2(int n)
/*Function used to calculate sum of numbers obtained from equation (n+1)^2 from 1 to n
  Assumes a natural number is input
  Prints numbers from n to 1 and their sum*/
{					
	if (n == 1)
	{
		printf("(%d + 1)^2 = ", n);

		return (n+1)*(n+1);
	}
	else
	{
		printf("(%d + 1)^2 + ", n);

		return sum2(n-1) + (n+1)*(n+1);
	}
}

int Fibonacci(int n)
/*Function used to find nth Fibonacci number
  Assumes non-negative integer input
  Prints the nth Fibonacci number*/
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return Fibonacci(n-1) + Fibonacci(n-2);
	}
}

int GCD(int a, int b)
/*Function used to find greatest common demoninator of two numbers
  Requires two numbers be entered
  Outputs the greatest common demoninator*/
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a % b);
	}
}

int Power(int a, int b)
/*Function used to find what n to the mth power is
  Requires two numbers entered
  Outputs n to mth power*/
{
	if (b == 1)
	{
		return a;
	}
	else
	{
		return a * Power(a, b - 1);
	}
}

int Print(int n)
/*Function used to print series of whole numbers from n to 1
  Assumes natural number entered
  Outputs series of whole numbers from n to 1*/
{
	if (n == 1)
	{
		printf("%d\n", n);	
	
		return n;
	}
	else
	{
		printf("%d ", n);
		
		return Print(n-1);
	}
}

int DrawTriangle(int n)
/*Function used to print upside-down triangle of asterisks
  Requires natural number be entered
  Prints upside-down triangle of asterisks*/
{
	int i;

	if (n == 1)
	{
		printf("*\n");

		return n;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			printf("*");
		}

		printf("\n");

		return DrawTriangle(n-1);
	}
}

int DrawTriangle2(int n)
/*Function used to print triangle of asterisks
  Requires natural number be entered
  Prints triangle of asterisks*/
{
	int i;

	if (n == 1)
	{
		printf("*\n");

		return n;
	}
	else
	{
		DrawTriangle2(n-1);

		for (i = 0; i < n; i++)
		{
			printf("*");
		}

		printf("\n");
	}
}

int sum1non(int n)
/*Function used to find sum of whole numbers from 1 to n
  Assumes natural number input
  Prints numbers from 1 to n and their sum*/
{
	int sum = 0, i = 1;

	printf("0 ");

	for (i; i <= n; i++)
	{
		printf("+ %d ", i);
		
		sum += i;
	}
	
	printf("= %d\n", sum);

	return 0;
}

int sum2non(int n)
/*Function used to find sum of numbers in form (n+1)^2 from 1 to n
  Assumes natural number entered
  Prints numbers in form (n+1)^2 from 1 to n and sum*/
{
	int sum = 0, i = 1;

	printf("0 ");

	for (i; i <= n; i++)
	{
		printf("+ (%d + 1)^2 ", i);

		sum += (i+1)*(i+1);
	}

	printf("= %d\n", sum);

	return 0;
}

int Fibonaccinon(int n)
/*Function used to show how nth Fibonacci number is found and the number
  Assumes non-negative whole number entered
  Prints Fibonacci numbers 0 through n*/
{
	int sum = 0, i = 1, fib1 = 0, fib2 = 1, tot = 0;

	if (n == 0)
	{
		printf("Fibonacci(0) ");
	}
	else if (n == 1)
	{
		printf("Fibonacci(1) ", fib1, fib2);
	
		tot = fib2;
	}
	else
	{
		printf("Fibonacci(%d) = %d ", n, fib1);

		tot = fib2;		

		for (i; i < n; i++)
		{
			sum = fib1 + fib2;
			fib1 = fib2;
	
			printf("+ %d ", fib2);

			fib2 = sum;
			tot += sum;
		}
	}
	printf("= %d\n", sum);

	return 0;
}

int GCDnon(int a, int b)
/*Function used to find greatest common demoninator and steps to get it
  Requires two numbers input
  Prints greatest common demoninator and steps to reach it*/
{
	int c;

	printf("(%d, %d) ", a, b);

	while (b != 0)
	{
		c = a;
		a = b;
		b = c % b;

		printf("-> (%d, %d) ", a, b);
	}

	printf("= %d\n", a);
}

int Powernon(int a, int b)
/*Function used to find n to the mth power
  Requires two numbers input
  Prints n to the mth power*/
{
	float c;

	c = a;

	printf("%d^%d = ", a, b);

	if (b > 0)
	{ 
		for (b; b > 1; b--)
		{
			c *= a;	
		}
	
		printf("%.0f\n", c);
	}
	else if (b < 0)
	{
		for (b; b < -1; b++)
		{
			c *= a;
		}
	
		c = 1/c;

		printf("%.3f\n", c);
	}
	else
	{
		c = 1;

		printf("%.0f\n", c);
	}

	return 0;
}

int Printnon(int n)
/*Function used to print series of whole numbers from n to 1
  Requires natural number be entered
  Prints list of whole numbers from n to 1*/
{
	for (n; n > 0; n--)
	{
		printf("%d ", n);
	}

	printf("\n");

	return 0;
}

int DrawTrianglenon(int n)
/*Function used to print upside-down triangle of asterisks
  Requires natural number be entered
  Prints upside-down triangle of asterisks*/
{
	int i;

	for (n; n > 0; n--)
	{
		for (i = 0; i < n; i++)
		{
			printf("*");
		}
	
		printf("\n");
	}
}

int DrawTriangle2non(int n)
/*Function used to print triangle of asterisks
  Requires natural number be entered
  Prints triangle of asterisks*/
{
	int i, t;

	for (t = 0; t < n; t++)
	{
		for (i = 0; i <= t; i++)
		{
			printf("*");
		}

		printf("\n");
	}
}
