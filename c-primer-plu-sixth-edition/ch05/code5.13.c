// 2020-11-06 created by Akson
// Code5.13 addemup.c

#include <stdio.h>

int main(void)
{
	int count, sum;

	count = 0;
	sum = 0;

	while(count++ < 20)
	{
		sum = sum + count;
	}

	printf("sum = %d\n", sum);

	return 0;
}