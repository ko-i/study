// 2020-12-15 created by Akson
// pe9.10

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 100

int palindrome(char * string);
char * s_gets(char * st, int n);

int main(int argc, char const *argv[])
{
	printf("Enter a string and I will judge whether it is a palindrome.\n");
	printf("String enter(nothing to quit): ");
	char str[MAXSIZE];

	while(s_gets(str, MAXSIZE) != NULL && str[0] != '\0')
	{
		printf("%s is%s a palindrome.\n", str, (palindrome(str) ? "" : " not"));

		printf("Next string enter(nothing to quit): ");
	}

	printf("Bye!\n");

	return 0;
}

int palindrome(char * string)
{
	int str_len = strlen(string);
	char* p_start = string;
	char* p_end = &string[str_len - 1];

	while(p_start < p_end)
	{
		while(!isalpha(*p_start) && p_start < p_end)
		{
			p_start++;
		}

		while(!isalpha(*p_end) && p_end > p_start)
		{
			p_end--;
		}

		if(p_start >= p_end)
		{
			break;
		}

		*p_start = tolower(*p_start);
		*p_end = tolower(*p_end);

		if(*p_start != *p_end)
		{
			return 0;
		}

		p_start++;
		p_end--;
	}

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
