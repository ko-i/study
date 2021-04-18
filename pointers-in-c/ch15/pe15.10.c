// 2020-12-21 created by Akson
// pe15.10

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAMELEN 50

int check_sum(const char* filename, unsigned int *result);

int main(int argc, char const *argv[])
{
	if(argc == 1)
	{
		printf("Enter a sentence and I will cacul its checksum.\n");
		printf("Sentence(EOF to quit): ");

		unsigned int ch = 0;
		unsigned int checksum = 0;
		while((ch = getchar()) != EOF)
		{
			checksum += ch;
		}

		printf("%u\n", checksum);
		exit(EXIT_SUCCESS);
	}
	else if(argc == 2)
	{
		if(strcmp("-f", argv[1]) == 0)
		{
			fprintf(stderr, "-f illegal when reading standard input\n");

			exit(EXIT_FAILURE);
		}
		else
		{
			unsigned int result = 0;
			if(check_sum(argv[1], &result) == 1)
			{
				printf("%u\n", result);
				exit(EXIT_SUCCESS);
			}

			fprintf(stderr, "Dispose %s failed.\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}

	int option_f = 0;
	int file_index = 1;
	if(strcmp("-f", argv[1]) == 0)
	{
		option_f = 1;
		file_index++;
	}

	for(; file_index < argc; file_index++)
	{
		unsigned int result = 0;
		if(check_sum(argv[file_index], &result) == 1)
		{
			if(option_f == 1)
			{
				char newfile[NAMELEN];
				strcpy(newfile, argv[file_index]);
				strcat(newfile, ".cks");
				FILE* fwp = fopen(newfile, "w");
				if(fwp == NULL)
				{
					fprintf(stderr, "Create %s failed.\n", newfile);
					continue;
				}

				fprintf(fwp, "%u\n", result);

				fclose(fwp);
			}
			else
			{
				printf("#%d: %s's checksum is %d\n", file_index, argv[file_index], result);
			}
		}
		else
		{
			fprintf(stderr, "Dispose %s failed.\n", argv[file_index]);
			continue;
		}
	}

	printf("Done! Bye!\n");

	return 0;
}

int check_sum(const char* filename, unsigned int *result)
{
	FILE* fp = fopen(filename, "r");
	if(fp == NULL)
	{
		fprintf(stderr, "Open %s failed.\n", filename);
		return 0;
	}

	*result = 0;
	int ch = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		*result += ch;
	}

	return 1;
}
