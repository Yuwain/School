#include <stdio.h>

void main()
{
	float costw, costc, costm, costa, age, HST = 0;

	printf("Cost of water: ");
	scanf("%f", &costw);
	printf("cost of chips: ");
	scanf("%f", &costc);
	printf("cost of milk: ");
	scanf("%f", &costm);
	printf("Age? ");
	scanf("%f", &age);

	costw *= 3;
	costc *= 4;
	costm *= 2;

	costa = costc+costm+costw;

	if (age < 65)
	{
		HST += costw * 0.13;
		HST += costc * 0.13;
		HST += costm * 0.13;
		
	}

	printf("Water 3 @ %.2f each ... $%.2f\n", costw/3, costw);
	printf("Chips 4 @ %.2f each ... $%.2f\n", costc/4, costc);
	printf("Milk  2 @ %.2f each ... $%.2f\n", costm/2, costm);
	printf("	Subtotal        $%.2f\n", costa);
	printf("	HST		$%.2f\n", HST);
	printf("	Total		$%.2f\n", HST+costa);
}
