// 2020-11-06 created by Akson

#include <stdio.h>

void Temperatures(double fa);

int main(void)
{
	double fa;
	printf("Please input Fa temperature(not a number for quit):");
	while(scanf("%lf", &fa) == 1)
	{
		Temperatures(fa);
		printf("Please input Fa temperature(not a number for quit):");
	}

	printf("Done!\n");

	return 0;
}

void Temperatures(double fa)
{
	double c = 5.0 / 9.0 * (fa - 32.0);
	printf("F: %.3f C: %.3f K: %.3f\n", fa, c, c + 273.16);
}

