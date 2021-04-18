// 2020-12-08 created by Akson
// pe6.3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

void reverse_string(char *string);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a string and I will reverse it!\n");
	printf("String enter(only [Enter] to quit): ");

	char str[MAXSIZE];

	while(s_gets(str, MAXSIZE) != NULL && str[0] != '\0')
	{
		printf("Oringinal string: %s\n", str);
		reverse_string(str);
		printf("After reverse:    %s\n", str);

		printf("Next string enter(only [Enter] to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

void reverse_string(char *string)
{
	char *ps = string;

	int str_len = 0;
	while(*ps != '\0')
	{
		str_len++;
		ps++;
	}

	ps = string;
	char *ps_bro = ps + str_len - 1;
	while(ps < ps_bro)
	{
		char temp = *ps;
		*ps = *ps_bro;
		*ps_bro = temp;
		ps++;
		ps_bro--;
	}
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
