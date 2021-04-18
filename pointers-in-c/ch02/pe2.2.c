// 2020-12-03 created by Akson
// pe2.2.c check the {} valid

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Enter a C source code and I will check if it is valid int number of '{' and '}'\n");
	printf("C source code enter(EOF to quit): ");

	int left_count = 0;
	int right_count = 0;

	int ch;
	while((ch = getchar()) != EOF)
	{
		if(ch == '{')
		{
			left_count++;
			continue;
		}

		if(ch == '}')
		{
			right_count++;
		}
	}

	if(left_count == right_count)
	{
		printf("This is a valid C source code, but it is only valid in {} count.\n");
	}
	else
	{
		printf("This is not a valid C source code, please check the numbers of {} pair.\n");
	}

	printf("Bye!\n");

	return 0;
}