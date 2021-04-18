// 2020-12-07 created by Akson
// pe5.1

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Enter a string and I will change upper letter to lower.\n");
	printf("String enter(EOF to quit): ");

	int ch;
	while((ch = getchar()) != EOF)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			ch += 32;
		}

		putchar(ch);
	}

	printf("Bye!\n");

	return 0;
}