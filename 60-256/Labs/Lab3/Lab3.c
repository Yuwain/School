#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int x;
	FILE *f, *p;
	char hold[100];

	if (argc == 3)
	{
		if ((f = fopen(argv[1], "r")) == NULL)
			fprintf(stderr, "Error opening file for reading\n");
		else
		{
			if ((p = fopen(argv[2], "w")) == NULL)
				fprintf(stderr, "Error opening file for writing\n");
			else
			{
				fseek(f, 0, SEEK_END);
				fseek(p, ftell(f), SEEK_SET);
				rewind(f);


				while (fgets(hold, 100, f) != NULL)
				{
					x = (0-strlen(hold));
					fseek(p, x, SEEK_CUR);
					fprintf(p, "%s", hold);
					fseek(p, x, SEEK_CUR);
				}

				fclose(f);
				fclose(p);
			}
		}
	}
	else
	{
		fprintf(stderr, "Invalid argument amount\n");
	}
}
