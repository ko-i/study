// 2020-12-02 created by Akson
// pe1.2.c print the input

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Please enter some string and I will repeat it!\n");
	printf("You string(EOF to quit): ");

	int ch;
	int line_count = 1;
	int is_first = 1;
	while((ch = getchar()) != EOF)
	{
		if(is_first)
		{
			printf("Line %d: ", line_count);
			is_first = 0;
		}

		putchar(ch);

		if(ch == '\n')
		{
			line_count++;
			is_first = 1;
			printf("Next string(EOF to quit): ");
		}
	}

	printf("\nBye!\n");

	return 0;
}