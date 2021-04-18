// 2020-12-05 created by Akson
// pe4.7.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void deblank(char string[]);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a string and a number i will delete constant space in it.\n");
	char str[MAXSIZE];

	printf("Enter a string(nothing to quit): ");
	while(s_gets(str, MAXSIZE) != NULL && str[0] != '\0')
	{
		deblank(str);
		printf("The string after delete space unnecessary: %s\n", str);
	}

	printf("Bye!\n");
	
	return 0;
}

void deblank(char string[])
{
	int str_len = strlen(string);
	if(str_len <= 1)
	{
		return;
	}

	char* pt = string;
	char* current = string;
	char* next = current + 1;

	while(*next != '\0')
	{
		if(*current == ' ')
		{
			if(*next == ' ')
			{
				current++;
				next++;
				continue;
			}
		}

		*pt = *current;
		pt++;
		current++;
		next++;
	}

	*pt = *current;
	pt++;
	*pt = '\0';
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