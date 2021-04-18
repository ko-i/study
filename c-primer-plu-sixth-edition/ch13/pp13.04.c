// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	int ch;

	if(argc == 1)
	{
		fprintf(stderr, "No file input.\n");
		exit(EXIT_FAILURE);
	}

	for(int i = 1; i < argc; i++)
	{
		if((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Can't open file: %s\n", argv[i]);
			exit(EXIT_FAILURE);
			continue;
		}

		while((ch = getc(fp)) != EOF)
		{
			putc(ch, stdout);
		}

		printf("\n");
	}

	printf("Done!\n");

	return 0;
}