// 2020-11-08 created by Akson

#include <stdio.h>

double imin(double m, double n);

int main(void)
{
	double m, n;
	printf("Enter twe number and I will get the smaller one.\n");
	scanf("%lf %lf", &m, &n);

	printf("%.2lf\n", imin(m, n));

	return 0;
}

double imin(double m, double n)
{
	return (m > n) ? m : n;
}