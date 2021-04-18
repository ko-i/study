// 2020-11-14 created by Akson
// Code16.9 ifdef.c

#include <stdio.h>

#define JUST_CHECKING
#define LIMIT 4

int main(void)
{
	int i;
	int total;

	for(i = 1; i <= LIMIT; i++)
	{
		total += 2 * i * i + 1;
#ifdef JUST_CHECKING
		printf("i = %d, running total = %d\n", i, total);
#endif
	}

	printf("Grand total = %d\n", total);

	return 0;
}