// 2020-12-11 created by Akson
// pe7.3

#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

int ascii_to_integer(char* string);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a string only have numbers and I will change it to Integer.\n");
	printf("String enter(no enter to quit): ");
	char str[MAXSIZE];

	while(s_gets(str, MAXSIZE) != NULL && str[0] != '\0')
	{
		printf("This is the number I got: %d\n", ascii_to_integer(str));

		printf("Next string enter(no enter to quit): ");
	}

	printf("Bye!\n");
	return 0;
}

int ascii_to_integer(char* string)
{
	int result = 0;

	char* ps = string;
	while(*ps != '\0')
	{
		result = result * 10 + *ps - '0';
		ps++;
	}

	return result;
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