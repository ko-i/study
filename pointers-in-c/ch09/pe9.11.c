// 2020-12-15 created by Akson
// pe9.11

#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

int count_the(char* str);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a string and I will count the number of \"the\" in it\n");
	printf("String enter(nothing to quit): ");

	char str[MAXSIZE];
	while(s_gets(str, MAXSIZE) != NULL && str[0] != '\0')
	{
		printf("Here have %d \"the\" in \"%s\".\n", count_the(str), str);

		printf("Next string enter(nothing to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int count_the(char* str)
{
	char str_cpy[MAXSIZE];
	strcpy(str_cpy, str);

	int count = 0;
	char whitespace[] = " ";
	char * token;

	for(token = strtok(str_cpy, whitespace); token != NULL; token = strtok(NULL, whitespace))
	{
		if(strcmp(token, "the") == 0)
		{
			count++;
		}
	}

	return count;
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