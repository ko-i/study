// 2020-11-08 created by Akson
// Code9.4 misuse.c

#include <stdio.h>

int imax();

int main(void)
{
	printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3));
	printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));

	return 0;
}

int imax(n, m)
int n, m;
{
	return (n > m ? n : m);
}