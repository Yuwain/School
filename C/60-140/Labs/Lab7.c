#include <stdio.h>

void main()
{
	int num, r, n, number = 0;
	float code, price, total, tot = 0, array[30][2] = {0};

	while(code != -1) 
	{
		printf("\n");
		printf("What is the item code? ");
		scanf("%f", &code);

		if(code == -1) 
		{
			break;
		}

		r = number;
		number ++;

		printf("What is the price of the item? $");
		scanf("%f", &price);
		printf("How many of the item were bought? ");
		scanf("%d", &num);
		
		tot = price*num;
		total += tot;
		
		for (r; r < number; r++)
		{ 
			array[r][0] = code;
			array[r][1] = tot;
		}
	}

	printf("\n");
	printf("Item Code \t\t\t Item Sales Income\n");

	for (n = 0; n < number; n++)
	{
		printf("%.0f \t\t\t\t$%.2f\n", array[n][0], array[n][1]);
	}

	printf("Number of items \t\t Total sales income\n");
	printf("%d \t\t\t\t$%.2f\n", number, total);
}
