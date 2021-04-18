// 2020-11-08 created by Akson

#include <stdio.h>

double power(double n, int p);

int main(void)
{
	double x, xpow;
	int exp;

	printf("Enter a number and the integer power to which the number will be rasied. Enter q to quit.\n");
	while(scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.6lf\n", x, exp, xpow);
		printf("Enter the next pair of numbers or q to quit.\n");
	}

	printf("Hope you enjoyed the power trip -- bye!\n");

	return 0;
}

double power(double n, int p)
{
	if(n == 0.0 && p == 0)
	{
		printf("Error!\n");

		return 0.0;
	}

	if(n == 0)
	{
		return 0.0;
	}

	if(p == 0)
	{
		return 1.0;
	}

	double pow = 1;
	int i;

	if(p > 0)
	{
		for(i = 1; i <=p; i++)
		pow *= n;
	}

	if(p < 0)
	{
		for(i = 1; i <= -p; i++)
		pow /= n;
	}

	return pow;
}