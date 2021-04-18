// 2020-11-08 created by Akson

#include <stdio.h>

void larger_of(double * a, double * b);

int main(void)
{
	double a, b;
	printf("Enter two numbers: \n");
	scanf("%lf %lf", &a, &b);

	printf("Before change: %.2lf %.2lf\n", a, b);
	larger_of(&a, &b);
	printf("After  change: %.2lf %.2lf\n", a, b);

	return 0;
}

void larger_of(double * a, double * b)
{
	if(*a > *b)
	{
		*b = *a;
	}
	else
	{
		*a = *b;
	}
}