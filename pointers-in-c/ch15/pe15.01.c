// 2020-12-19 created by Akson
// pe15.1

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("I will repeat what you say!\n");
	printf("You say(EOF fot end): ");

	int ch;
	while((ch = getchar()) != EOF)
	{
		putchar(ch);
	}

	printf("\nBye!\n");

	return 0;
}