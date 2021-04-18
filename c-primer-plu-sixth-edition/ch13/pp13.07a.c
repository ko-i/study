// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 256

int main(int argc, char const *argv[])
{
	FILE *fp1;
	FILE *fp2;

	char str1[SIZE];
	char str2[SIZE];

	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s [filename1] [filename2]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if((fp1 = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Open file: \"%s\" failed.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if((fp2 = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Open file: \"%s\" failed.\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	bool file1end = false;
	bool file2end = false;

	while(!file1end || !file2end)
	{
		if(!file1end && fgets(str1, SIZE, fp1) != NULL)
		{
			printf("%s", str1);	
		}
		else
		{
			file1end = true;
		}

		if(!file2end && fgets(str2, SIZE, fp2) != NULL)
		{
			printf("%s", str2);	
		}
		else
		{
			file2end = true;
		}
	}

	printf("Done!\n");

	return 0;
}