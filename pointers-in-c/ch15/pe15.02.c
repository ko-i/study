// 2020-12-19 created by Akson
// pe15.2

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int main(int argc, char const *argv[])
{
	FILE* fp;

	if((fp = fopen("data", "r")) == NULL)
	{
		fprintf(stderr, "No such file: %s\n", "data");
		exit(EXIT_FAILURE);
	}

	char str[MAXSIZE];
	while(fgets(str, MAXSIZE, fp) != NULL)
	{
		fputs(str, stdout);
	}

	fclose(fp);
	printf("\nBye!\n");

	return 0;
}