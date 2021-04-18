// 2020-11-06 created by Akson
// Code5.4 squares.c

#include <stdio.h>

int main(void)
{
	int num = 1;

	while(num < 21)
	{
		printf("%4d %6d\n", num, num * num);
		num = num + 1;
	}

	return 0;
}