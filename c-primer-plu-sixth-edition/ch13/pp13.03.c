// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	FILE *fp;
	char filename[40];
	printf("Please enter a filename: ");
	scanf("%s", filename);

	if((fp = fopen(filename, "r+")) == NULL)
	{
		fprintf(stderr, "Can't open file: %s\n", filename);
		exit(EXIT_FAILURE);
	}

	int ch;
	while((ch = getc(fp)) != EOF)
	{
		fseek(fp, -1, SEEK_CUR);
		putc(toupper(ch), fp);
	}

	printf("Done!\n");
	fclose(fp);

	return 0;
}