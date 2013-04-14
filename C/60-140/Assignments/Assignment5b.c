// I was going to follow the structure chart, but I decided it would be easier with arrays

#include <stdio.h>

void main()
{
	int r, c;
	float price[2][7] = {0};

	printf("Original Retail Price \t Whole Sale Price\n");

	for (r = 0; r < 2; r ++)
		for (c = 0; c < 2; c ++)
			scanf("%f", &price[r][c]);

	for (r = 0; r < 2; r ++)
		for (c = 2; c < 7; c ++)
		{
			if (c == 2)
				price[r][c] = price[r][0] * 0.9;
			else
				price[r][c] = price[r][c-1] * 0.9;
			
			if (price[r][c] < price[r][1])
				price[r][c] = price[r][1];
		}

	printf("Retail Price \t Whole Sale \t Monday \t Tuesday \t"
		"Wednesday \t Thursday \t Friday\n");

	for (r = 0; r < 2; r ++)
	{
		for (c = 0; c < 7; c ++)
			printf("$%.2f\t \t", price[r][c]);

		printf("\n");
	}
}
