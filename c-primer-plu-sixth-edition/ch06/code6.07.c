// 2020-11-06 created by Akson
// Code6.7 truth.c

#include <stdio.h>

int main(void)
{
	int n = 3;

	while(n)
		printf("%2d is true\n", n--);
	printf("%2d is false\n", n);

	n = -3;
	while(n)
		printf("%2d is true\n", n++);
	printf("%2d is false\n", n);

	return 0;

}