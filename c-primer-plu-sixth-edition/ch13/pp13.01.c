// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *fp;
	int ch;
	char filename[50];

	printf("Please enter a file's name: ");
	scanf("%s", filename);

	if((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file: %s\n", filename);
	}

	while((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
	}

	printf("Done!\n");

	return 0;
}