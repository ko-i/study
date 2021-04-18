// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	float a;
	float b;

	printf("Please input a float:");
	scanf( "%f", &a);
	printf("The input is %.2f or %2.1e.\n", a, a);

	printf("Please input another float:");
	scanf( "%f", &b);
	printf("The input is %+.3f or %4.3E.\n", b, b);

	return 0;
}