//Jeremy High 	- 103306452
//Assignment 3 	- 60-256-01
//October 26th, 2012

//Inclusions
#include <stdio.h>
#include <string.h>

//Input: A file to read from, a file to write to, the number of columns and rows, and the size of the picture
//Output: The picture flipped and saved into another file
//Purpose: To flip the picture and save it into another file
void flipSave(FILE *fr, FILE *fw, int cols, int rows, long int size)
{
  	int i;
  	char image[cols];

  	fseek(fw, size, SEEK_SET);
  
  	for (i = 0; i < rows; ++i)
	{
    	fread(image, 1, cols, fr);
    	fseek(fw, -cols, SEEK_CUR);
    	fwrite(image, 1, cols, fw);
   		fseek(fw, -cols, SEEK_CUR);
  	}
}

int main(int argc, char *argv[])
{
  	FILE *fr, *fw;
 	long int size;
	char hold[100];
	int cols, rows;

  	if ((fr=fopen(argv[1], "r")) != NULL)
  	{
		if ((fw=fopen(argv[2], "w")) != NULL)
		{
			fseek(fr, 0, SEEK_END);
  			size = ftell(fr);
 			rewind(fr);

  			fgets(hold, 100, fr);
  			fputs(hold, fw);
  			
  			fscanf(fr,"%d %d\n", &cols, &rows);
  			fprintf(fw,"%d %d\n", cols, rows);
  
  			fgets(hold, 100, fr);
  			fputs(hold, fw);

			flipSave(fr, fw, cols, rows, size);
		}
		else
		{
			fprintf(stderr, "Error opening file %s for writing\n"
							"Usage: ./a.out <Image> <New Image>\n", argv[2]);
		}
	}
	else
	{
		fprintf(stderr, "Error opening file %s for reading\n"
						"Usage: ./a.out <Image> <New Image>\n", argv[1]);
	}

	fclose(fr);
  	fclose(fw);

  	return 0;
}
