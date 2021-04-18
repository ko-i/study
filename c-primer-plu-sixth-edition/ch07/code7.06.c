// 2020-11-07 created by Akson
// Code7.6 chcount.c

#include <stdio.h>

#define PERIOD '.'

int main(void)
{
	char ch;
	int charcount = 0;

	while((ch = getchar()) != PERIOD)
	{
		if(ch != '"' && ch != '\'')
		{
			charcount++;
		}
	}

	printf("There are %d non-quote characters.\n", charcount);

	return 0;
}