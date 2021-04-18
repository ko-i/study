// 2020-12-21 created by Akson
// pe15.9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAMELEN 100
#define LINELEN 510
#define STRLEN 50

void find_str(const char* target_str, const char* filename);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	if(argc < 3 )
	{
		printf("Enter a string to find.\n");
		printf("Target string: ");
		char target_str[STRLEN];
		scanf("%s", target_str);
		while(getchar() != '\n');

		printf("\nNow, enter the files' name which you want search.\n");
		printf("File's name(nothing to quit): ");
		char filename[FILENAMELEN];

		while(s_gets(filename, FILENAMELEN) != NULL && filename[0] != '\0')
		{
			find_str(target_str, filename);

			printf("Next file's name(nothing to quit): ");
		}
	}
	else
	{
		for(int i = 2; i < argc; i++)
		{
			find_str(argv[1], argv[i]);
		}
	}

	printf("\nDone! Bye!\n");

	return 0;
}

void find_str(const char* target_str, const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if(fp == NULL)
	{
		fprintf(stderr, "Open %s failed.\n", filename);
		return;
	}

	char line[LINELEN];
	int line_index = 0;

	while(fgets(line, LINELEN, fp) != NULL)
	{
		line_index++;
		if(strstr(line, target_str) != NULL)
		{
			printf("%s: %d\n", filename, line_index);
		}
	}

	fclose(fp);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
		{
			*find = '\0';
		}
		else
		{
			while(getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}
