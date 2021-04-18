// 2020-11-08 created by Akson
// Code9.13 swap1.c

#include <stdio.h>

void interchanged(int u, int v);

int main(void)
{
	int x = 5, y = 10;

	printf("Originally x = %d and y = %d.\n", x, y);
	interchanged(x, y);
	printf("Now x = %d and y = %d.\n", x, y);

	return 0;
}

void interchanged(int u, int v)
{
	int temp;

	temp = u;
	u = v;
	v = temp;
}