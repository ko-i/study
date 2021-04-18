// 2020-12-15 created by Akson
// pe9.16

#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

int format(char * format_string, char const * digit_string);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a format string and i will use it to format some digit string.\n");
	printf("Format string enter(nothing to quit): ");

	char format_string[MAXSIZE];
	char digit_string[MAXSIZE];
	while(s_gets(format_string, MAXSIZE) != NULL && format_string[0] != '\0')
	{
		printf("\nFormat string entered: %s\n", format_string);

		printf("Enter a digit string and i will format it.\n");
		printf("Digit string enter(nothing to quit): ");
		if(s_gets(digit_string, MAXSIZE) != NULL && digit_string[0] != '\0')
		{
			if(format(format_string, digit_string) == 0)
			{
				printf("Some thing wrong!\n");

				printf("Next format string enter(nothing to quit): ");
				continue;
			}

			printf("The format string: %s\n", format_string);
		}

		printf("Next format string enter(nothing to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int format(char * format_string, char const * digit_string)
{
	char * pf = format_string;
	char const * pd = digit_string;

	int format_count = 0;
	int digit_count = 0;

	int have_dot = 0;

	while(*pf != '\0')
	{
		if(*pf == '#')
		{
			format_count++;
		}

		if(*pf == '.')
		{
			have_dot = 1;
		}

		pf++;
	}

	while(*pd != '\0')
	{
		digit_count++;
		pd++;
	}

	if(digit_count > format_count)
	{
		return 0;
	}

	pf--;
	pd--;

	while(pd != digit_string)
	{
		if(*pf == '#')
		{
			*pf = *pd;
			pd--;
		}

		if(*pf == '.')
		{
			have_dot = 0;
		}

		pf--;
	}

	while(*pf != '#')
	{
		pf--;
	}

	*pf = *pd;

	if(pf == format_string)
	{
		return 1;
	}

	pf--;
	if(have_dot)
	{
		while(*pf != '.')
		{
			*pf = '0';
			pf--;
		}

		pf--;
		*pf = '0';

		if(pf == format_string)
		{
			return 1;
		}
		pf--;
	}


	while(pf != format_string)
	{
		*pf = ' ';
		pf--;
	}

	*pf = ' ';
	return 1;
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
