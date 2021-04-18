// 2020-11-06 created by Akson
// Code5.2 shoes2.c

#include <stdio.h>

#define ADJUST 7.31

int main(void)
{
	const double SCALE = 0.333;
	double shoe, foot;

	printf("Shoe size(men's)     foot length\n");

	shoe = 3.0;
	while(shoe < 18.5)
	{
		foot = SCALE * shoe + ADJUST;
		printf("%10.1f %15.2f inches\n", shoe, foot);
		shoe += 1.0;
	}

	return 0;
}