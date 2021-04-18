// 2020-12-07 created by Akson
// pe6.1

#include <stdio.h>

char const *find_char(char const *source, char const *chars);

int main(int argc, char const *argv[])
{
	char *source = "ABCDEF";
	char *chars_1 = "XYZ";
	char *chars_2 = "XRCQEF";

	char const *find = NULL;
	// test1
	find = find_char(source, chars_1);
	if(find)
	{
		printf("Find it! The first letter in %s find in %s is %c.\n", source, chars_1, *find);
	}
	else
	{
		printf("%s and %s have no common letters.\n", source, chars_1);
	}

	// test2
	find = find_char(source, chars_2);
	if(find)
	{
		printf("Find it! The first letter in %s find in %s is %c.\n", source, chars_2, *find);
	}
	else
	{
		printf("%s and %s have no common letters.\n", source, chars_2);
	}

	return 0;
}

char const *find_char(char const *source, char const *chars)
{
	char const *pc = chars;

	while(*pc != '\0')
	{
		char const *ps = source;
		while(*ps != '\0')
		{
			if(*pc == *ps)
			{
				return pc;
			}
			ps++;
		}

		pc++;
	}

	return NULL;
}