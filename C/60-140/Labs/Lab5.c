#include <stdio.h>

void main()
{
	int select;

	printf("Do you want program 1 (RentCar) or program 2 (IncomeTax)? ");
	scanf("%d", &select);
	printf("\n");

	switch (select) {
	case 1:
		RentCar();
		break;
	case 2:
		IncomeTax();
		break;
	default:
		printf("Error - not an option\n");
		break;
	}
}

int RentCar(void)
{
	float days, miles, cost1, cost2;

	printf("For how many days do you plan to rent? ");
	scanf("%f", &days);
	printf("How many miles do you plan to drive? ");
	scanf("%f", &miles);
	printf("\n");

	cost1 = days * 40;
	cost2 = (days * 30) + (0.15 * miles);

	printf("Plan 1 would cost $%.2f and plan 2 would cost $%.2f\n", cost1, cost2);

	if (cost1 >= cost2) {
		if (cost1 > cost2) {
			printf("It would be cheaper to use plan 2\n");
		}
		else {
			printf("Both plans would cost the same\n");
		}
	}
	else {
		printf("It would be cheaper to use plan 1\n");
	}

	return 0;
}

int IncomeTax(void)
{
	float income, tax;
	char *taxes[20];

	printf("What is your annual income? $");
	scanf("%f", &income);

	if (income >= 200000) {
		*taxes = "50% tax";
		tax = income * 0.5;
	}
	else {
		if (income >= 150000) {
			*taxes = "36% tax";
			tax = income * 0.36;
		}
		else {
			if (income >= 100000) {
				*taxes = "30% tax";
				tax = income * 0.30;
			}
			else {
				if (income >= 50000) {
					*taxes = "20% tax";
					tax = income * 0.20;
				}
				else {
					if (income >= 20000) {
						*taxes = "10% tax";
						tax = income * 0.10;
					}
					else {
						*taxes = "no taxes";
						tax = income * 0;
					}
				}
			}
		}
	}

	printf("You pay %s on $%.2f which amounts to $%.2f\n", *taxes, income, tax);

	return 0;
}
