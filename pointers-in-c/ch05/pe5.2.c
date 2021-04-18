// 2020-12-07 created by Akson
// pe5.2

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Enter a string and I will encrpyt it.\n");
	printf("String enter(EOF to quit): ");

	int ch;
	while((ch = getchar()) != EOF)
	{
		if(ch >= 'A' && ch <= 'Z')
		{
			ch += 13;
			if(ch > 'Z')
			{
				ch -= 26;
			}
		}

		if(ch >= 'a' && ch <= 'b')
		{
			ch += 13;
			if(ch > 'b')
			{
				ch -= 26;
			}
		}
		
		putchar(ch);
	}

	printf("Bye!\n");

	return 0;
}