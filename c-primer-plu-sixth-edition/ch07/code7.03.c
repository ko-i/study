// 2020-11-06 created by Akson
// Code7.3 cypher2

#include <stdio.h>
#include <ctype.h> 

int main(void)
{
	char ch;

	while((ch = getchar()) != '\n')
	{
		if(isalpha(ch))
		{
			putchar(ch + 1);
		}
		else
		{
			putchar(ch);
		}
	}

	putchar(ch);

	return 0;
}