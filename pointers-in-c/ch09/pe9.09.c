// 2020-12-14 created by Akson
// pe9.9

#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

int count_chars(char const *str, char const * chars);

int main(int argc, char const *argv[])
{
	// some test
	printf("Enter a string: ");
	char str[MAXSIZE];
	scanf("%s", str);
	while(getchar() != '\n')
	{
		continue;
	}

	printf("Enter a target string, and i will count the char's number in string1 appear in this string.\n");
	printf("Enter the target: ");
	char target[MAXSIZE];
	scanf("%s", target);
	while(getchar() != '\n')
	{
		continue;
	}

	printf("The char's number in target is: %d\n", count_chars(str, target));

	printf("\nBye!\n");

	return 0;
}

int count_chars(char const *str, char const * chars)
{
	int count = 0;

	while(*str != '\0')
	{
		if(strchr(chars, *str))
		{
			count++;
		}

		str++;
	}

	return count;
}