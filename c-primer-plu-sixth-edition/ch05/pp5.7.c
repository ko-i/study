// 2020-11-06 created by Akson

#include <stdio.h>

double cube(double num);

int main(void)
{
	double num;

	printf("Please enter a number: ");
	scanf("%lf", &num);

	printf("The number is %.2lf, its cube is %.2lf\n", num, cube(num));
}

double cube(double num)
{
	return num * num * num;
}