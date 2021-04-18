// 2020-11-08 created by Akson
// Cpde9.14 swap2.c

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
	printf("Originally u = %d and v = %d.\n", u, v);
	int temp;
	temp = u;
	u = v;
	v = temp;
	printf("Now u = %d and v = %d.\n", u, v);
}