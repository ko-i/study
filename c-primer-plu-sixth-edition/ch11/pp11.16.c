// 2020-11-10 created by Akson

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int ch;
	if(argc == 1 || (argc == 2 && argv[1][1] == 'p'))
	{
		printf("Enter a sentence and i will repeat it.(EOF to stop)\n");
		while((ch = getchar()) != EOF)
		{
			putchar(ch);
		}
	}
	else if(argc == 2 && argv[1][1] == 'u')
	{
		printf("Enter a sentence and i will upper the lowercase in it.(EOF to stop)\n");
		while((ch = getchar()) != EOF)
		{
			putchar(toupper(ch));
		}
	}
	else if(argc == 2 && argv[1][1] == 'l')
	{
		printf("Enter a sentence and i will lower the upcase in it.(EOF to stop)\n");
		while((ch = getchar()) != EOF)
		{
			putchar(tolower(ch));
		}
	}

	return 0;
}