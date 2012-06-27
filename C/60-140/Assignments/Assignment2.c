// Jeremy High - 103306452
// Assignment 2 - 03-60-140-01
// October 3rd, 2011

#include <stdio.h>
#include <math.h>

int main(void)
{
	float yw, yl, hw, hl;
	float yaf, yam, haf, ham, gaf, gam, ypf, hpf, ypm, hpm, hour, minute, second;
	float spd, s, min, hr, m;

	m = 0.3048;
	spd = 2;

	printf("What is the length of the yard in feet?\t\t");
	scanf("%f", &yl);
	printf("What is the width of the yard in feet?\t\t");
	scanf("%f", &yw);
	printf("What is the length of the house in feet?\t");
	scanf("%f", &hl);
	printf("What is the width of the house in feet?\t\t");
	scanf("%f", &hw);

	yaf = yw*yl;
	haf = hw*hl;
	gaf = yaf-haf;
	yam = yaf*m*m;
	ham = haf*m*m;
	gam = gaf*m*m;
	ypf = 2*(yw+yl);
	hpf = 2*(hw+hl);
	ypm = ypf*m;
	hpm = hpf*m;
	s = gaf/spd;
	min = s/60;
	hr = min/60;
	hour = floor(hr);
	minute = floor((hr-hour)*60);
	second = ((((hr-hour)*60)-minute)*60);

	printf("The time required to cut the grass in the yard is:\t %.0f hours, %.0f minutes, %.0f seconds\n", hour, minute, second);
	printf("\n");
	printf("The area of the yard in square feet is:\t\t\t %.2f sq. ft.\n", yaf);
	printf("The area of the yard in square meters is:\t\t %.2f sq. m.\n", yam);
	printf("The area of the house in square feet is:\t\t %.2f sq. ft.\n", haf);
	printf("The area of the house in square meters is:\t\t %.2f sq. m.\n", ham);
	printf("The area of the grass in square feet is:\t\t %.2f sq. ft.\n", gaf);
	printf("The area of the grass in square meters is:\t\t %.2f sq. m.\n", gam);
	printf("\n");
	printf("The perimeter of the yard in feet is:\t\t\t %.2f ft.\n", ypf);
	printf("The perimeter of the yard in meters is:\t\t\t %.2f m.\n", ypm);
	printf("The perimeter of the house in feet is:\t\t\t %.2f ft.\n", hpf);
	printf("The perimeter of the house in meters is:\t\t %.2f m.\n", hpm);

	return 0;

}
