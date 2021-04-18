// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	double inches;
	printf("Please input your inches length:");
	scanf("%lf", &inches);
	printf("You are %.0lf inches tall and %.0lf cm tall.\n", inches, inches * 2.54);

	return 0;
}