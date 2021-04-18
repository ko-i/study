// 2020-11-11 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 256

int main(int argc, char const *argv[])
{
	FILE *fp;
	char ch;
	char str[MAXSIZE];

	if(argc != 3)
	{
		fprintf(stderr, "Usage %s [char] [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		if((fp = fopen(argv[2], "r")) == NULL)
		{
			fprintf(stderr, "Can't open file %s\n", argv[2]);
			exit(EXIT_FAILURE);
		}
	}

	ch = argv[1][0];

	while(fgets(str, MAXSIZE, fp) != NULL)
	{
		if(strchr(str, ch) != NULL)
		{
			printf("%s", str);
		}
	}

	fclose(fp);

	return 0;
}