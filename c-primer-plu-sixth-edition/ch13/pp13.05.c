// 2020-11-12 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char * st, int n);

int main(int argc, char *argv[])
{
	FILE *fa, *fs;
	int files = 0;
	char file_app[SLEN];
	char file_src[SLEN];
	int ch;

	if(argc <= 2)
	{
		fprintf(stderr, "Usage: %s [targetfile] [sourcefile1] [sourcefile2] ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if((fa = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Can't open file: %s as target.\n", argv[1]);
	}

	if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}

	for(int i = 2; i < argc; i++)
	{
		if(strcmp(argv[1], argv[i]) == 0)
		{
			fputs("Can't append file to itself\n", stderr);
			continue;
		}
		else if((fs = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s\n", argv[i]);
		}
		else
		{
			if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}

			append(fs, fa);

			if(ferror(fs) != 0)
			{
				fprintf(stderr, "Error in reading file %s.\n", file_src);
			}
			if(ferror(fa) != 0)
			{
				fprintf(stderr, "Error in writing file %s.\n", file_app);
			}

			fclose(fs);
			files++;
			printf("File %s appended.\n", argv[i]);
		}
	}

	printf("Done appending. %d files appended.\n", files);

	rewind(fa);
	printf("%s contents:\n", file_app);
	while((ch = getc(fa)) != EOF)
	{
		putchar(ch);
	}
	
	puts("\nDone displaying.");
	fclose(fa);

	return 0;
}

void append(FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, dest);
	}
}