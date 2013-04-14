#include <stdio.h>

void main()
{
	int location, game;
	float north, south, avgn, avgs, pointn, points;

	for (game = 1; game < 4; game++)
	{
		printf("Type game location, North team points, and South team points\nGame %d: ", game);
		scanf("%d %f %f", &location, &north, &south);

		switch (location)
		{
		case 1:
			south = south + 10;
			break;
		case 2:
			north = north + 10;
			break;
		}

		pointn += north;
		points += south;
	}

	avgn = pointn/3;
	avgs = points/3;

	printf("Average points for North team is:\t %.2f \n", avgn);
	printf("Average points for South team is:\t %.2f \n", avgs);
}
