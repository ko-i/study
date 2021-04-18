// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main()
{
	FILE *in, *out;
	int ch;
	char filename[LEN];
	char name[LEN];
	int count = 0;

	printf("Please enter a file: \n");
	scanf("%s", filename);

	if((in = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", filename);
		exit(EXIT_FAILURE);
	}

	strncpy(name, filename, LEN - 5);
	name[LEN - 5] = '\0';
	strcat(name, ".red");
	if((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't created output file.\n");
		exit(3);
	}

	while((ch = getc(in)) != EOF)
	{
		if(count++ % 3 == 0)
		{
			putc(ch, out);
		}
	}

	if(fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Error in closing files\n");
	}

	return 0;
}