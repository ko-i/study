// 2020-11-08 created by Akson

#include <stdio.h>

double cal(double m, double n);

int main(void)
{
	double num1;
	double num2;

	printf("Enter to number and i will calcu their ave.\n");
	scanf("%lf %lf", &num1, &num2);

	printf("%.2lf and %.2lf aver is %.2lf", num1, num2, cal(num1, num2));

	return 0;
}

double cal(double m, double n)
{
	return 1.0 / ((1.0 / m + 1.0 / n) / 2.0); 
}