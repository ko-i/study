// 2020-11-05 created by Akson

#include <stdio.h>

int main(void)
{
	double f;
	printf("Enter a floating-point value:");
	scanf("%lf", &f);
	printf("fixed-point notation: %lf\n", f);
	printf("exponential: %e\n", f);
	printf("p notation: %a\n", f);

	return 0;
}