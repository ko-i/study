// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE * fp;
	char target;
	int ch;
	int count = 0;

	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s char [filename1] [filename2] ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	target = argv[1][0];

	if(argc == 2)
	{
		fp = stdin;
		printf("Enter a string and I will count the %c numbers in it(EOF to quit).\n", target);
		while((ch = getchar()) != EOF)
		{
			if(ch == target)
			{
				count++;
			}
		}

		printf("I got %d %c in the string.\n", count, target);
	}
	else
	{
		for(int i = 2; i < argc; i++)
		{
			if((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open file: %s.\n", argv[i]);
				continue;
			}

			while((ch = getc(fp)) != EOF)
			{
				if(ch == target)
				{
					count++;
				}
			}
		}

		printf("I got %d %c in the string.\n", count, target);
	}

	printf("Done!\n");

	return 0;
}