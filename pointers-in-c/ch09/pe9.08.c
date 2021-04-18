// 2020-12-14 created by Akson
// pe9.8

#include <stdio.h>

char* my_strnchr(char const * str, int ch, int which);

int main(int argc, char const *argv[])
{
	// some test

	return 0;
}

char* my_strnchr(char const * str, int ch, int which)
{
	char* result = NULL;
	int count = 0;

	while(*str != '\0')
	{
		if(*str == ch)
		{
			count++;
			if(count == which)
			{
				result = str;
			}
		}

		str++;
	}

	return result;
}