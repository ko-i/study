// 2020-11-06 created by Akson
// code5.5 wheat.c

#include <stdio.h>

#define SQUARES 64

int main(void)
{
	const double CROP = 2E16;
	double current, total;
	int count = 1;

	printf("square     grains added     total grains      fraction of  world total\n");

	total = current = 1.0;
	
	while(count < SQUARES)
	{
		printf("%4d %20.lf %20.lf %1.lf\n", count, current, total, total / CROP);
		
		current = current * 2;
		total = total + current;
		count = count + 1;
	}

	printf("That is all!\n");

	return 0;
}