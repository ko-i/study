// 2020-12-14 created by Akson
// pe9.7

#include <stdio.h>

char* my_strrchr(char const * str, int ch);

int main(int argc, char const *argv[])
{
	// some test

	return 0;
}

char* my_strrchr(char const * str, int ch)
{
	char* result = NULL;

	while(*str != '\0')
	{
		if(*str == ch)
		{
			result = str;
		}

		str++;
	}

	return result;
}