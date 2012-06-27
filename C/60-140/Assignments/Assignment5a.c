#include <stdio.h>
#include <math.h>

int BinaryC(int);
int Complement1(int);
void Printnum(int, int);

void main()
{
	char cont, junk;
	int dec, dec2, bin, numpos = 0, numneg = 0, sumpos = 0, sumneg = 0, numall = 0, sumall = 0;

	start:
	printf("Are there any more numbers to convert, Y/N?\n");
	scanf("%c", &cont);

	if (cont == 'Y' || cont == 'y')
	{
	
		printf("What is the number you want to convert?\n");
		scanf("%d", &dec);
		
		if (dec < 0)
		{
			numneg ++;
			sumneg += dec;
			dec2 = dec * -1;
			bin = BinaryC(dec2);
			bin = Complement1(bin);
		}
		else
		{
			if (dec == 0)
			{
				numall ++;
				bin = BinaryC(dec);
			}

			numpos ++;
			sumpos += dec;
			bin = BinaryC(dec);
		}

		Printnum(dec, bin);
	
		scanf("%c", &junk);	
		goto start;
	}
	else
	{
		if (cont == 'N' || cont == 'n')
		{
			sumall = sumneg + sumpos;
			numall += numneg + numpos;
			
			bin = BinaryC(numpos);
			printf("Number of positive numbers processed =\t%3d or %08d in binary\n", numpos, bin);
			
			bin = BinaryC(numneg);
			printf("Number of negative numbers processed =\t%3d or %08d in binary\n", numneg, bin);
			
			bin = BinaryC(numall);
			printf("Number of all numbers processed =\t%3d or %08d in binary\n", numall, bin);
			
			bin = BinaryC(sumpos);
			printf("Sum of positive numbers processed =\t%3d or %08d in binary\n", sumpos, bin);
	
			if (sumneg < 0)
			{
				sumneg *= -1;
				bin = BinaryC(sumneg);
				bin = Complement1(bin);
				sumneg *= -1;
			}
			else
			{
				bin = BinaryC(sumneg);
			}

			printf("Sum of negative numbers processed =\t%3d or %08d in binary\n", sumneg, bin);

			if (sumall < 0)
			{
				sumall *= -1;
				bin = BinaryC(sumall);
				bin = Complement1(bin);
				sumall *= -1;
			}
			else
			{
				bin = BinaryC(sumall);
			}

			printf("Sum of all numbers processed =\t\t%3d or %08d in binary\n", sumall, bin);

			printf("Thank you for using our binary conversion software\n");
		}
		else
		{
			scanf("%c", &junk);
			printf("Invalid option\n");
			goto start;
		}
	}
}

int BinaryC(int decimal)
{
	int binary = 0, quotient = 0, remainder = 0, power = 0;

	begin:
	quotient = decimal/2;
	remainder = decimal % 2;
	binary += (remainder * pow(10, power));

	while (quotient !=0)
	{
		decimal = quotient;
		power ++;
		goto begin;
	}

	return (binary);
}

int Complement1(int binary)
{
	int comp = 0;

	comp = 11111111 - binary;

	return (comp);
}

void Printnum (int decimal, int binary)
{
	printf("Number is %d and binary is %08d\n", decimal, binary);
}
