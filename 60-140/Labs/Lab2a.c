#include <stdio.h>

int main(void)
{
	int num1, num2;
	int sumdiv;
	int n1d1, n1d2, n1d3, n1d4, n2d1, n2d2, n2d3, n2d4, n3d1, n3d2, n3d3, n3d4;

	printf("Type the first four digit number:\t");
	scanf("%d", &num1);
	printf("Type the second four digit number:\t");
	scanf("%d", &num2);

	n1d4 = num1 % 10;
	n1d3 = (num1 % 100)/10;
	n1d2 = (num1 % 1000)/100;
	n1d1 = num1/1000;
	n2d4 = num2 % 10;
	n2d3 = (num2 % 100)/10;
	n2d2 = (num2 % 1000)/100;
	n2d1 = num2/1000;
	n3d4 = (n1d4 + n2d4)/2;
	n3d3 = (n1d3 + n2d3)/2;
	n3d2 = (n1d2 + n2d2)/2;
	n3d1 = (n1d1 + n2d1)/2;

	sumdiv = (n3d1*1000)+(n3d2*100)+(n3d3*10)+n3d4;

	printf("Your new number is %d.\n", sumdiv);
	return 0;
}
