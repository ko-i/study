// 2020-11-07 created by Akson
// Code8.1 echo.c

#include <stdio.h>

int main(void)
{
	char ch;

	while((ch = getchar()) != '#')
	{
		putchar(ch);
	}

	printf("\n");

	return 0;
}