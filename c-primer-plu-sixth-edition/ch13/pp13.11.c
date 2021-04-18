// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main(int argc, char const *argv[])
{
	FILE *fp;
	char str[SIZE];

	if(argc != 3)
	{
		fprintf(stderr, "Usage: %s string filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Can't open the file: %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while(fgets(str, SIZE, fp) != NULL)
	{
		if(strstr(str, argv[1]))
		{
			fputs(str, stdout);
		}
	}

	printf("Done!\n");

	return 0;
}