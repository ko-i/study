// 2020-11-08 created by Akson

#include <stdio.h>

void my_order(double * num1, double * num2, double * num3);

int main(void)
{
	double num1, num2, num3;

	printf("Enter three numbers.\n");
	scanf("%lf %lf %lf", &num1, &num2, &num3);

	printf("Before. num1: %.2lf, num2: %.2lf, num3: %.2lf\n", num1, num2, num3);
	my_order(&num1, &num2, &num3);
	printf("After.  num1: %.2lf, num2: %.2lf, num3: %.2lf\n", num1, num2, num3);

	return 0;
}

void my_order(double * num1, double * num2, double * num3)
{
	double temp;

	if(*num1 > *num2)
	{
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}

	if(*num1 > *num3)
	{
		temp = *num1;
		*num1 = *num3;
		*num3 = temp;
	}

	if(*num2 > *num3)
	{
		temp = *num2;
		*num2 = *num3;
		*num3 = temp;
	}
}