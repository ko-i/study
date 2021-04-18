// 2020-11-07 created by Akson
// Code8.2 echo_eof.c

#include <stdio.h>

int main(void)
{
	int ch;

	while((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
	
	printf("Done!\n");

	return 0;
}