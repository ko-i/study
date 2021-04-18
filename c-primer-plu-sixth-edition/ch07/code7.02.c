// 2020-11-06 created by Akson
// Code7.2 cypher1.c

#include <stdio.h>
#define SPACE ' '

int main(void)
{
	char ch;

	ch = getchar();
	while(ch != '\n')
	{
		if(ch == SPACE)
		{
			putchar(ch);
		}
		else
		{
			putchar(ch + 1);
		}
		ch = getchar();
	}

	putchar(ch);

	return 0;
}