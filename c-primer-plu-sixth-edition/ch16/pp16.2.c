// 2020-11-15 created by Akson

#include <stdio.h>

#define AVE(X, Y) ((2 * (X) * (Y)) / ((X) + (Y)))

int main(void)
{
	double num1;
	double num2;

	printf("Enter two number: ");
	while(scanf("%lf %lf", &num1, &num2) == 2)
	{
		printf("ave: %.2lf\n", AVE(num1, num2));

		printf("Enter two number: ");
	}

	return 0;
}