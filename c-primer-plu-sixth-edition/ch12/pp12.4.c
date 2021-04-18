// 2020-11-11 created by Akson

#include <stdio.h>

static int count = 0;

int func_count(void);

int main(void)
{
	for(int i = 0; i < 5; i++)
	{
		printf("The func has been call for %d times.\n", func_count());
	}

	return 0;
}

int func_count(void)
{
	return ++count;
}