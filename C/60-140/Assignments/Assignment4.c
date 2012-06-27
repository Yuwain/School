#include <stdio.h>
#include <math.h>

double WasherWeight(void);
double CircleArea(void);
double PrintWeights(void);

double numA, thkA, densA, inA, outA, numB, thkB, densB, inB, outB, numC, thkC, densC, inC, outC, numD, thkD, densD, inD, outD;
double totA, totB, totC, totD, tot;
double pi = 3.14159265358979, arA, arB, arC, arD;

int main(void)
{
	printf("Enter quantity, thickness, density, inner diameter, and outer diameter of washer type A: ");
	scanf("%lf %lf %lf %lf %lf", &numA, &thkA, &densA, &inA, &outA);
	printf("Enter quantity, thickness, density, inner diameter, and outer diameter of washer type B: ");
	scanf("%lf %lf %lf %lf %lf", &numB, &thkB, &densB, &inB, &outB);
	printf("Enter quantity, thickness, density, inner diameter, and outer diameter of washer type C: ");
	scanf("%lf %lf %lf %lf %lf", &numC, &thkC, &densC, &inC, &outC);
	printf("Enter quantity, thickness, density, inner diameter, and outer diameter of washer type D: ");
	scanf("%lf %lf %lf %lf %lf", &numD, &thkD, &densD, &inD, &outD);

	WasherWeight();
	PrintWeights();

	return 0;
}

double WasherWeight(void)
{
	CircleArea();

	totA = thkA * densA * arA * numA;
	totB = thkB * densB * arB * numB;
	totC = thkC * densC * arC * numC;
	totD = thkD * densD * arD * numD;
	tot = totA + totB + totC + totD;
}

double CircleArea(void)
{
	inA = (inA / 2)*(inA / 2) * pi;
	outA = (outA / 2)*(outA / 2) * pi;
	arA = outA - inA;

	inB = (inB / 2)*(inB / 2) * pi;
	outB = (outB / 2)*(outB / 2) * pi;
	arB = outB - inB;

	inC = (inC / 2)*(inC / 2) * pi;
	outC = (outC / 2)*(outC / 2) * pi;
	arC = outC - inC;

	inD = (inD / 2)*(inD / 2) * pi;
	outD = (outD / 2)*(outD / 2) * pi;
	arD = outD - inD;

}

double PrintWeights(void)
{
	printf("Washer Type \t Qty \t Thickness \t Density \t\t Weight\n");
	printf("A \t\t %.0lf \t %.1lfcm \t\t %.1lfg/cm^3 \t\t %.2fg\n", numA, thkA, densA, totA);
	printf("B \t\t %.0lf \t %.1lfcm \t\t %.1lfg/cm^3 \t\t %.2fg\n", numB, thkB, densB, totB);
	printf("C \t\t %.0lf \t %.1lfcm \t\t %.1lfg/cm^3 \t\t %.2fg\n", numC, thkC, densC, totC);
	printf("D \t\t %.0lf \t %.1lfcm \t\t %.1lfg/cm^3 \t\t %.2fg\n", numD, thkD, densD, totD);
	printf("Total Weight ************************************** \t\t %.2fg\n", tot);

}

