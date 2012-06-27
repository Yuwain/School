#include <stdio.h>

int main(void)
{
	float F, C;

	printf("Input the temperature in degrees Fahrenheit:\t");
	scanf("%f", &F);

	C = (F-32)*5/9;

	printf("The temperature in degrees Celsuis is %.2f.\n", C);
	return 0;
}
