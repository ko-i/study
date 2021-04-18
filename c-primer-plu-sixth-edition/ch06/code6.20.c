// 2020-11-06 created by Akson
// Code6.20 power.c

#include <stdio.h>

double power(double n, int p);

int main(void)
{
	double x, xpow;
	int exp;

	printf("Enter a number and the positive integer power to which the number will be rasied. Enter q to quit.\n");
	while(scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter the next pair of numbers or q to quit.\n");
	}

	printf("Hope you enjoyed the power trip -- bye!\n");

	return 0;
}

double power(double n, int p)
{
	double pow = 1;
	int i;

	for(i = 1; i <=p; i++)
		pow *= n;

	return pow;
}