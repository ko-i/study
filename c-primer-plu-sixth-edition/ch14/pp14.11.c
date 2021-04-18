// 2020-11-16 created by Akson

#include <stdio.h>
#include <math.h>

#define NUMLEN 100

void transform(double * source, double * target, int size, double(*pfun)(double num));

int main(void)
{
	double nums[NUMLEN];
	for(int i = 0; i < NUMLEN; i++)
	{
		nums[i] = (double) i * 2.0;
	}

	printf("This this the numbers:\n");
	for(int i = 0; i < NUMLEN; i++)
	{
		printf("%6.2lf ", nums[i]);
		if(i % 10 == 9)
		{
			printf("\n");
		}
	}

	double target[NUMLEN];
	transform(nums, target, NUMLEN, sin);

	printf("\nThis this the numbers after transform:\n");
	for(int i = 0; i < NUMLEN; i++)
	{
		printf("%6.2lf ", target[i]);
		if(i % 10 == 9)
		{
			printf("\n");
		}
	}

	return 0;
}

void transform(double * source, double * target, int size, double(*pfun)(double num))
{
	for(int i = 0; i < NUMLEN; i++)
	{
		target[i] = pfun(source[i]);
	}
}