// 2020-12-21 created by Akson
// pe15.8

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FILENAMELEN 100
#define BUFFERSIZE 16

int main(int argc, char const *argv[])
{
	FILE* fp;

	char filename[FILENAMELEN];
	if(argc == 1)
	{
		printf("Enter a file's name which you want to check hex dump.\n");
		printf("File name: ");
		scanf("%s", filename);

		if((fp = fopen(filename, "rb")) == NULL)
		{
			fprintf(stderr, "Open %s failed.\n", filename);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if((fp = fopen(argv[1], "rb")) == NULL)
		{
			fprintf(stderr, "Open %s failed.\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}

	unsigned int offset = 0;
	char buffer[BUFFERSIZE];
	size_t read_byte_count = 0;
	while((read_byte_count = fread(buffer, 1, BUFFERSIZE, fp)) == BUFFERSIZE)
	{
		printf("%06X ", offset);
		offset += BUFFERSIZE;

		for(int i = 0; i < BUFFERSIZE; i++)
		{
			printf("%02X", buffer[i]);

			if(i != 0 && i % 4 == 3)
			{
				printf(" ");
			}
		}

		printf(" *");
		for(int i = 0; i < BUFFERSIZE; i++)
		{
			if(isprint(buffer[i]))
			{
				printf("%c", buffer[i]);
			}
			else
			{
				printf(".");
			}
		}

		printf("*\n");
	}

	// the last line
	if((read_byte_count = fread(buffer, 1, BUFFERSIZE, fp)) != 0)
	{
		printf("%06X ", offset);

		for(int i = read_byte_count - 1; i < BUFFERSIZE; i++)
		{
			buffer[i] = 0;
		}

		for(int i = 0; i < BUFFERSIZE; i++)
		{
			printf("%02X", buffer[i]);

			if(i != 0 && i % 4 == 3)
			{
				printf(" ");
			}
		}

		printf(" *");
		for(int i = 0; i < BUFFERSIZE; i++)
		{
			if(isprint(buffer[i]))
			{
				printf("%c", buffer[i]);
			}
			else
			{
				printf(".");
			}
		}

		printf("*\n");
	}

	fclose(fp);
	printf("\nDone! Bye!\n");

	return 0;
}